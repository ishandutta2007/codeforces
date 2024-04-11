{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  kr,root,kg,q,n,i,j,qqq:longint;
  mr:int64;
  nom,used,prs,krs,kf,last,ss,ff,tt:array[0..100500]of longint;
  res:array[0..100500]of int64;
  p,g,pred:array[0..200500]of longint;
  procedure qs(l,r:longint);
    var
      xx,tmp,i,j:longint;
    begin
      i:=l;j:=r;
      xx:=tt[i+random(j-i+1)];
      while (i<=j)do begin
        while (xx>tt[i])do inc(i);
        while (xx<tt[j])do dec(j);
        if (i>j)then break;
        tmp:=ss[i];ss[i]:=ss[j];ss[j]:=tmp;
        tmp:=ff[i];ff[i]:=ff[j];ff[j]:=tmp;
        tmp:=tt[i];tt[i]:=tt[j];tt[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  function predset(x:longint):longint;
    begin
      if (prs[x]<>x)then prs[x]:=predset(prs[x]);
      predset:=prs[x];
    end;
  procedure dfs(x,px:longint);
    var
      ii,y:longint;
    begin
      used[x]:=qqq;
      ii:=last[x];
      kf[x]:=krs[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)then begin
          dfs(y,x);
          inc(kf[x],kf[y]);
        end;
        ii:=pred[ii];
      end;
    end;
  procedure dfs2(x,px:longint);
    var
      ii,y:longint;
    begin
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)then begin
          res[p[ii]]:=int64(kf[root]-kf[y])*kf[y];
          dfs2(y,x);
        end;
        ii:=pred[ii];
      end;
    end;
begin
  randomize;
  read(n);
  for i:=1 to n-1 do read(ss[i],ff[i],tt[i]);
  for i:=1 to n-1 do nom[i]:=i;
  qs(1,n-1);
  qqq:=0;
  for i:=1 to n do prs[i]:=i;
  for i:=1 to n do krs[i]:=1;
  i:=1;
  while (i<=n-1)do begin
    j:=i;
    while (j<n-1)and(tt[j+1]=tt[j])do inc(j);
    inc(qqq);
    for q:=i to j do begin
      ss[q]:=predset(ss[q]);
      ff[q]:=predset(ff[q]);
    end;
    for q:=i to j do begin
      last[ss[q]]:=0;
      last[ff[q]]:=0;
      kf[ss[q]]:=-1;
      kf[ff[q]]:=-1;
      pred[q-i+1]:=0;
      pred[q-i+1+(j-i+1)]:=0;
    end;
    kg:=0;
    for q:=i to j do begin
      inc(kg);g[kg]:=ff[q];p[kg]:=nom[q];pred[kg]:=last[ss[q]];last[ss[q]]:=kg;
      inc(kg);g[kg]:=ss[q];p[kg]:=nom[q];pred[kg]:=last[ff[q]];last[ff[q]]:=kg;
    end;
    for q:=i to j do
      if (used[ss[q]]<>qqq)then begin
        root:=ss[q];
        dfs(ss[q],0);
        dfs2(ss[q],0);
      end;
    for q:=i to j do begin
      ss[q]:=predset(ss[q]);
      ff[q]:=predset(ff[q]);
      prs[ff[q]]:=ss[q];
      inc(krs[ss[q]],krs[ff[q]]);
    end;
    i:=j+1;
  end;
  mr:=0;kr:=0;
  for i:=1 to n-1 do begin
    if (res[i]>mr)then begin
      mr:=res[i];
      kr:=0;
    end;
    if (res[i]=mr)then inc(kr);
  end;
  writeln(mr+mr,' ',kr);
  for i:=1 to n-1 do
    if (res[i]=mr)then write(i,' ');
  writeln;
end.
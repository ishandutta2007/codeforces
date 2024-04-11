{$r-,q-,s-,i-,o+}
var
  kt,ss,n,i,x,y,kg:longint;
  f1:array[0..100500]of int64;
  a,g,t,pred,f2,last:array[0..200500]of longint;
  procedure qs(l,r:longint);
    var
      i,j,tmp:longint;
      xx:int64;
    begin
      i:=l;j:=r;
      xx:=f1[t[l+random(r-l+1)]];
      while (i<=j)do begin
        while (xx<f1[t[i]])do inc(i);
        while (xx>f1[t[j]])do dec(j);
        if (i>j)then break;
        tmp:=t[i];t[i]:=t[j];t[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  procedure dfs(x,px:longint);
    var
      ost,i,ii:longint;
      cr:int64;
    begin
      if (f1[x]<>-1)then exit;
      ii:=last[x];
      while (ii>0)do begin
        if (g[ii]<>px)then dfs(g[ii],x);
        ii:=pred[ii];
      end;
      kt:=0;
      ii:=last[x];
      while (ii>0)do begin
        if (g[ii]<>px)then begin
          inc(kt);
          t[kt]:=g[ii];
        end;
        ii:=pred[ii];
      end;
      qs(1,kt);
      ost:=a[x];
      cr:=0;
      if (px<>-1)then begin
        dec(ost);
        cr:=1;
      end;
      for i:=1 to kt do begin
        if (ost<1)then break;
        dec(ost);
        cr:=cr+f1[t[i]]+1;
      end;
      for i:=1 to kt do begin
        ii:=ost;
        if (f2[t[i]]<ii)then ii:=f2[t[i]];
        cr:=cr+2*ii;
        dec(ost,ii);
      end;
      f1[x]:=cr;
      f2[x]:=ost;
    end;
begin
  fillchar(last,sizeof(last),$0);
  fillchar(pred,sizeof(pred),$0);
  kg:=0;
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  read(ss);
  fillchar(f1,sizeof(f1),$FF);
  fillchar(f2,sizeof(f2),$FF);
  dfs(ss,-1);
  writeln(f1[ss]);
end.
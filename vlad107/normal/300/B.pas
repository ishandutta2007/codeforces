{$r-,q-,s-,i-,o+}
var
  u,kq,kt,nt,j,x1,x2,n,m,kg,i,x,y:longint;
  rev,nom,t,a,b,g,pred,last:array[0..500500]of longint;
  q:array[0..500500,0..5]of longint;
  used:array[0..500500]of boolean;

  procedure dfs(x:longint);
    var
      ii:longint;
    begin
      inc(kt);t[kt]:=x;
      nom[x]:=nt;
      rev[nt]:=x;
      ii:=last[x];
      used[x]:=true;
      while (ii>0)do begin
        if (not used[g[ii]])then dfs(g[ii]);
        ii:=pred[ii];
      end;
    end;

begin
  read(n,m);
  kg:=0;
  fillchar(last,sizeof(last),$0);
  for i:=1 to m do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  fillchar(used,sizeof(used),false);
  nt:=0;
  for i:=1 to n do 
    if (not used[i])then begin
      kt:=0;
      inc(nt);
      dfs(i);
      if (kt>3)then begin
        writeln(-1);
        exit;
      end;
      if (kt=3)then begin
        inc(kq);
        q[kq][1]:=t[1];
        q[kq][2]:=t[2];
        q[kq][3]:=t[3];
        continue;
      end;
      if (kt=2)then begin
        inc(x2);
        b[x2]:=nt;
      end else begin
        inc(x1);
        a[x1]:=nt;
      end;
    end;
  if (x1<x2)or((x1-x2)mod 3<>0)then begin
    writeln(-1);exit;
  end;
  for i:=1 to x2 do begin
    inc(kq);u:=0;
    for j:=1 to n do if (nom[j]=a[i])then begin
      inc(u);
      q[kq][u]:=j;
    end;
    for j:=1 to n do if (nom[j]=b[i])then begin
      inc(u);
      q[kq][u]:=j;
    end;
  end;
  i:=x2+1;
  while (i<=x1)do begin
    inc(kq);
    q[kq][1]:=rev[a[i]];
    q[kq][2]:=rev[a[i+1]];
    q[kq][3]:=rev[a[i+2]];
    inc(i,3);
  end;
  for i:=1 to kq do writeln(q[i][1],' ',q[i][2],' ',q[i][3]);
end.
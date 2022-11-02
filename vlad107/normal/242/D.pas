{$r-,q-,s-,i-,o+}
var
  n,m,i,x,y,kg:longint;
  t,u,a,g,pred,last:array[0..500500]of longint;
  procedure dfs(x:longint);
    var
      y,ii:longint;
    begin
      t[x]:=0;
      dec(u[x]);
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        dec(u[y]);
        if (u[y]=a[y])then dfs(y);
        ii:=pred[ii];
      end;
    end;
begin
  read(n,m);
  for i:=1 to n do begin t[i]:=1;u[i]:=1;end;
  for i:=1 to m do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
    inc(u[x]);inc(u[y]);
  end;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do if (u[i]=a[i])then dfs(i);
  kg:=0;for i:=1 to n do inc(kg,t[i]);
  writeln(kg);for i:=1 to n do if (t[i]=1)then write(i,' ');
  writeln;
end.
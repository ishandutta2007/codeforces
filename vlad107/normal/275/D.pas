var
  n,i,x,y,kg:longint;
  g,pred,last:array[0..500500]of longint;
  t,f,u:array[0..500500]of int64;
  
  procedure dfs(x,px:longint);
    var
      ct,mf,mu:int64;
      ii:longint;
      
    begin
      ii:=last[x];
      mf:=0;mu:=0;
      while (ii>0)do begin
        if (g[ii]<>px)then dfs(g[ii],x);
        if (f[g[ii]]>mf)then mf:=f[g[ii]];
        if (u[g[ii]]>mu)then mu:=u[g[ii]];
        ii:=pred[ii];
      end;
      f[x]:=mf;u[x]:=mu;
      ct:=t[x]+mf-mu;
      if (ct<0)then f[x]:=f[x]-ct else u[x]:=u[x]+ct;
    end;

begin
  read(n);
  for i:=1 to n-1 do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  for i:=1 to n do read(t[i]);
  dfs(1,0);
  writeln(f[1]+u[1]);
end.
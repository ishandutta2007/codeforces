{$r-,q-,s-,i-,o+}
var
  res:extended;
  n,i,kg,x,y:longint;
  pred,last,g:array[0..500500]of longint;

  procedure dfs(x,px,t:longint);
    var
      ii:longint;
    begin
      res:=res+1/t;
      ii:=last[x];
      while (ii>0)do begin
        if (g[ii]<>px)then dfs(g[ii],x,1+t);
        ii:=pred[ii];
      end;
    end;

begin
  read(n);
  for i:=1 to n-1 do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  dfs(1,0,1);
  writeln(res:0:10);
end.
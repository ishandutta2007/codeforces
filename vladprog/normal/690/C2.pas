var
  n,m,a,b,i,ans:longint;
  top,next,cur:array[1..200000]of longint;

function dfs(v,p:longint):longint;
var
  a,b,i,k:longint;
begin
  a:=0;
  b:=0;
  i:=cur[v];
  while i<>0 do
    begin
      if top[i]<>p then
        begin
          k:=dfs(top[i],v);
          if b<k+1 then
            b:=k+1;
          if a<b then
            begin
              a:=a xor b;
              b:=a xor b;
              a:=a xor b
            end;
        end;
      i:=next[i]
    end;
  if ans<a+b then
    ans:=a+b;
  dfs:=a
end;

begin
  read(n,m);
  fillchar(cur,sizeof(cur),0);
  for i:=1 to m do
    begin
      read(a,b);
      top[i*2-1]:=b;
      next[i*2-1]:=cur[a];
      cur[a]:=i*2-1;
      top[i*2]:=a;
      next[i*2]:=cur[b];
      cur[b]:=i*2
    end;
  ans:=0;
  dfs(1,0);
  writeln(ans)
end.
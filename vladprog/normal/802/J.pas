{$macro+}
{$define free}

{$ifdef free}
uses math;
{$endif}

var
  n,i,u,v,c,m:longint;
  top,next,w,cur:array[0..200]of longint;

procedure dfs(v,p,d:longint);
var
  i:longint;
begin
  m:=max(m,d);
  i:=cur[v];
  while i<>0 do
    begin
      if top[i]<>p then
        dfs(top[i],v,d+w[i]);
      i:=next[i]
    end
end;

begin
  read(n);
{$ifdef free}
  fillchar(cur,sizeof(cur),0);
{$endif}
  for i:=1 to n-1 do
    begin
      read(u,v,c);
      
      top[2*i-1]:=v;
      next[2*i-1]:=cur[u];
      w[2*i-1]:=c;
      cur[u]:=2*i-1;
      
      top[2*i]:=u;
      next[2*i]:=cur[v];
      w[2*i]:=c;
      cur[v]:=2*i
    end;
  m:=0;
  dfs(0,-1,0);
  writeln(m)
end.
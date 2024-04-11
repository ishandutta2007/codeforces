var n,i,j,cnt,ans,x,y:longint;
    tot,last,pre,other,r,son:array[0..800007] of longint;
procedure insert(u,v:longint);
begin
  inc(cnt);
  other[cnt]:=v;pre[cnt]:=last[u];
  last[u]:=cnt;
end;
procedure dfs1(u,father:longint);
var q,v:longint;
begin
  if (father<>0) then son[u]:=1;
  q:=last[u];
  while (q>0) do
  begin
    v:=other[q];
    if (v<>father) then
	begin
	  dfs1(v,u);
	  son[u]:=son[u]+1;
	end;
	q:=pre[q];
  end;
end;
procedure dfs(u,pr,ppr,father:longint);
var q,v,now:longint;
begin
  now:=1;while  (now=pr) or (now=ppr) do inc(now);
  q:=last[u];
  while (q>0) do
  begin
    v:=other[q];
    if (v<>father) then
	begin
	  r[v]:=now;
	  dfs(v,now,pr,u);
	  inc(now);while (now=pr) or (now=ppr) do inc(now);
	end;
	q:=pre[q];
  end;
end;
begin
  readln(n);cnt:=0;ans:=0;
  fillchar(tot,sizeof(tot),0);
  for i:=1 to n-1 do
  begin
    readln(x,y);
    insert(x,y);
    insert(y,x);
    inc(tot[x]);inc(tot[y]);
  end;
  dfs1(1,0);
  for i:=1 to n do
	if (son[i]+1>ans) then ans:=son[i]+1;
  writeln(ans);
  r[1]:=1;dfs(1,1,1,0);
  for i:=1 to n do
	write(r[i],' ');
  writeln;
end.
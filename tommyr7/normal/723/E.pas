var t,l,m,n,i,j,ans,u,v,tot:longint;
	deg:array[0..300] of longint;
	r:array[0..100000,1..2] of longint;
	vis:array[0..100000] of boolean;
	next,last,other:array[0..100000] of longint;
procedure insert(x,y:longint);
begin
  inc(tot);
  next[tot]:=last[x];
  last[x]:=tot;
  other[tot]:=y;
  inc(tot);
  next[tot]:=last[y];
  last[y]:=tot;
  other[tot]:=x;
end;
procedure dfs(x:longint);
var i,j:longint;
begin
  i:=last[x];
  while (i>0) do
  begin
    if not(vis[i div 2]) then
	begin
	  vis[i div 2]:=true;
	  dfs(other[i]);
	  if (i div 2<=m) then
	  begin
	    r[i div 2,1]:=x;
	    r[i div 2,2]:=other[i];
	  end;
	end;
	i:=next[i];
  end;
end;
begin
  readln(t);
  for l:=1 to t do
  begin
    readln(n,m);
    fillchar(vis,sizeof(vis),false);
    fillchar(deg,sizeof(deg),0);
    fillchar(r,sizeof(r),false);
    fillchar(next,sizeof(next),0);
    fillchar(last,sizeof(last),0);
    fillchar(other,sizeof(other),0);
    tot:=1;
    ans:=0;
    for i:=1 to m do
	begin
	  readln(u,v);
	  insert(u,v);
	  inc(deg[u]);
	  inc(deg[v]);
	end;
	for i:=1 to n do
		if (deg[i] mod 2=1) then insert(i,n+1) else inc(ans);
	for i:=1 to n do
		dfs(i);
	writeln(ans);
	for i:=1 to m do
		writeln(r[i,1],' ',r[i,2]);
  end;
end.
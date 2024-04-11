var a,b,ans,last,pre,other:array[0..400007] of longint;
    n,i,j,tot:longint;
	vis:array[0..400007] of boolean;
procedure insert(u,v:longint);
begin
  inc(tot);
  other[tot]:=v;
  pre[tot]:=last[u];
  last[u]:=tot;
end;
procedure dfs(u,now:longint);
var q,v:longint;
begin
  if vis[u] then exit;
  vis[u]:=true;
  ans[u]:=now;
  q:=last[u];
  while (q>0) do
  begin
    v:=other[q];
    dfs(v,3-now);
    q:=pre[q];
  end;
end;
begin
  readln(n);
  fillchar(last,sizeof(last),0);
  fillchar(pre,sizeof(pre),0);
  fillchar(other,sizeof(other),0);
  tot:=0;
  for i:=1 to n do
  begin
    readln(a[i],b[i]);
    insert(a[i],b[i]);
    insert(b[i],a[i]);
  end;
  for i:=1 to n do
  begin
    insert(2*i-1,2*i);
    insert(2*i,2*i-1);
  end;
  fillchar(ans,sizeof(ans),0);
  fillchar(vis,sizeof(vis),false);
  for i:=1 to 2*n do
	dfs(i,1);
  for i:=1 to n do
	writeln(ans[a[i]],' ',ans[b[i]]);
end.
var n,m,t,i,j,ans,anss,now:longint;
    dis:array[0..5000,1..3] of longint;
	f,pre:array[0..5000,0..5000] of longint;
	path:array[0..5000] of longint;
begin
  readln(n,m,t);
  for i:=1 to n do
	for j:=1 to n do
	  f[i,j]:=maxlongint div 2;
  fillchar(pre,sizeof(pre),0);
  for i:=1 to m do
    readln(dis[i,1],dis[i,2],dis[i,3]);
  f[1,1]:=0;
  for i:=2 to n do
	for j:=1 to m do
	begin
	  if (f[dis[j,1],i-1]+dis[j,3]<f[dis[j,2],i]) then
	  begin
		f[dis[j,2],i]:=f[dis[j,1],i-1]+dis[j,3];
	    pre[dis[j,2],i]:=dis[j,1];
	  end;
	end;
  ans:=0;
  for i:=1 to n do
	if (f[n,i]<=t) and (i>ans) then ans:=i;
  writeln(ans);
  fillchar(path,sizeof(path),0);
  now:=n;
  anss:=ans;
  while (now<>1) do
  begin
    path[ans]:=now;
    now:=pre[now,ans];
    dec(ans);
  end;
  write(1,' ');
  for i:=2 to anss do
	write(path[i],' ');
  writeln;
end.
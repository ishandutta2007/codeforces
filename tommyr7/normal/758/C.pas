var n,m,x,y,i,j:longint;
    k,kk,ansmax,ansmin,ans,now:int64;
	f:array[0..207,0..207] of int64;
begin
  readln(n,m,k,x,y);
  kk:=k;
  fillchar(f,sizeof(f),0);
if (n<>1) then
begin
  now:=(n+n-2)*m;
  ans:=k div now;
  for i:=1 to n do
	for j:=1 to m do
	  if (i=1) or (i=n) then f[i,j]:=ans else f[i,j]:=ans+ans;
  k:=k mod now;
  for i:=1 to n do
	for j:=1 to m do
	begin
	  dec(k);
	  if (k>=0) then inc(f[i,j]);
	end;
  for i:=n-1 downto 2 do
	for j:=1 to m do
	begin
	  dec(k);
	  if (k>=0) then inc(f[i,j]);
	end;
  ansmax:=-1;ansmin:=kk;ans:=f[x,y];
  for i:=1 to n do
	for j:=1 to m do
	begin
	  if (f[i,j]>ansmax) then ansmax:=f[i,j];
	  if (f[i,j]<ansmin) then ansmin:=f[i,j];
	end;
end else
begin
  now:=k div m;
  for i:=1 to m do
	f[1,i]:=now;
  k:=k mod m;
  for i:=1 to m do
  begin
    dec(k);
    if (k>=0) then inc(f[1,i]);
  end;
    ansmax:=-1;ansmin:=kk;ans:=f[x,y];
  for i:=1 to n do
	for j:=1 to m do
	begin
	  if (f[i,j]>ansmax) then ansmax:=f[i,j];
	  if (f[i,j]<ansmin) then ansmin:=f[i,j];
	end;
end;
  writeln(ansmax,' ',ansmin,' ',ans);
end.
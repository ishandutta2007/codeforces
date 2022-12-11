uses math;
var n,m,i,j,now,q,lx,rx,last:longint;
    x,tot,anss:array[0..500007] of longint;
	ans:boolean;
function deal(i,j:longint):longint;
begin
  exit((i-1)*m+j);
end;
begin
  readln(n,m);
  fillchar(x,sizeof(x),0);
  for i:=1 to n do
  begin
    for j:=1 to m do
	  read(x[(i-1)*m+j]);
	readln;
  end;
  for i:=1 to m do
  begin
    now:=1;
    while (now<=n) do
	begin
	  last:=now;
	  while (now<=n-1) and (x[deal(now,i)]<=x[deal(now+1,i)]) do inc(now);
	  for j:=last to now do
		tot[deal(j,i)]:=now-j+1;
	  inc(now);
	end;
  end;
  for i:=1 to n do
  begin
    anss[i]:=0;
    for j:=1 to m do
	  anss[i]:=max(anss[i],tot[deal(i,j)]);
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(lx,rx);ans:=false;
	if (anss[lx]>=rx-lx+1) then ans:=true;
	if ans then writeln('Yes') else writeln('No');
  end;
end.
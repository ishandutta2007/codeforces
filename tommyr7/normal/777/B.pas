var n,i,j,now,ans1,ans2:longint;
    a,b:array[0..1007] of longint;
	ch:char;
procedure qsort1(lx,rx:longint);
var i,j,m,t:longint;
begin
  i:=lx;j:=rx;m:=a[random(rx-lx+1)+lx];
  repeat
	while (a[i]<m) do inc(i);
	while (a[j]>m) do dec(j);
	if (i<=j) then
	begin
	  t:=a[i];a[i]:=a[j];a[j]:=t;
	  inc(i);dec(j);
	end;
  until (i>j);
  if (i<rx) then qsort1(i,rx);
  if (lx<j) then qsort1(lx,j);
end;
procedure qsort2(lx,rx:longint);
var i,j,m,t:longint;
begin
  i:=lx;j:=rx;m:=b[random(rx-lx+1)+lx];
  repeat
	while (b[i]<m) do inc(i);
	while (b[j]>m) do dec(j);
	if (i<=j) then
	begin
	  t:=b[i];b[i]:=b[j];b[j]:=t;
	  inc(i);dec(j);
	end;
  until (i>j);
  if (i<rx) then qsort2(i,rx);
  if (lx<j) then qsort2(lx,j);
end;
begin
  randomize;
  readln(n);
  for i:=1 to n do
  begin
    read(ch);
    a[i]:=ord(ch)-48;
  end;readln;
  for i:=1 to n do
  begin
    read(ch);
    b[i]:=ord(ch)-48;
  end;readln;
  qsort1(1,n);qsort2(1,n);
  now:=1;
  for i:=1 to n do
	if (b[i]>=a[now]) then inc(now);
  ans1:=now-1;
  now:=1;
  for i:=1 to n do
	if (b[i]>a[now]) then inc(now);
  ans2:=now-1;
  writeln(n-ans1);writeln(ans2);
end.
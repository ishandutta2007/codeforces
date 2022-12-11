var n,x,y,i,j,t:longint;
    a:array[0..100000] of longint;
	ans1,ans2:int64;
	ans:real;
procedure qsort(lx,rx:longint);
var i,j,m,t:longint;
begin
  i:=lx;j:=rx;m:=a[(i+j) div 2];
  repeat
	while (a[i]>m) do inc(i);
	while (a[j]<m) do dec(j);
	if (i<=j) then
	begin
	  t:=a[i];a[i]:=a[j];a[j]:=t;
	  inc(i);dec(j);
	end;
  until (i>j);
  if (i<rx) then qsort(i,rx);
  if (j>lx) then qsort(lx,j);
end;
begin
  readln(n,x,y);
  for i:=1 to n do
	read(a[i]);
  readln;
  if (x>y) then
  begin
    t:=x;
    x:=y;
    y:=t;
  end;
  qsort(1,n);
  ans1:=0;ans2:=0;
  for i:=1 to x do
	ans1:=ans1+a[i];
  for i:=x+1 to x+y do
	ans2:=ans2+a[i];
  ans:=(ans1/x)+(ans2/y);
  writeln(ans:0:8);
end.
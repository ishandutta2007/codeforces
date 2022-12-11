var n,i,j:longint;
    a,b:array[0..3007] of longint;
	f:array[0..3007,0..3007] of int64;
	now:int64;
procedure qsort(lx,rx:longint);
var i,j,m,t:longint;
begin
  m:=random(rx-lx)+lx;
  i:=lx;j:=rx;m:=b[m];
  repeat
	while (b[i]<m) do inc(i);
	while (b[j]>m) do dec(j);
	if (i<=j) then
	begin
	  t:=b[i];b[i]:=b[j];b[j]:=t;
	  inc(i);dec(j);
	end;
  until (i>j); 
  if (i<rx) then qsort(i,rx);
  if (j>lx) then qsort(lx,j);
end;
begin
  randomize;
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    a[i]:=a[i]-i;
    b[i]:=a[i];
  end;
  readln;
  qsort(1,n);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
  begin
    now:=99999999999999999;
    for j:=1 to n do
	begin
	  if (f[i-1,j]<now) then now:=f[i-1,j];
	  f[i,j]:=abs(a[i]-b[j])+now;
	end;
  end;
  now:=99999999999999999;
  for i:=1 to n do
	if (f[n,i]<now) then now:=f[n,i];
  writeln(now);
end.
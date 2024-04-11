var n,i,tot,x,y,z,t:longint;
    a:array[0..100007] of longint;
	flag,flag1:boolean;
procedure qsort(lx,rx:longint);
var i,j,m,t:longint;
begin
  m:=random(rx-lx)+lx;
  i:=lx;j:=rx;m:=a[m];
  repeat
	while (a[i]<m) do inc(i);
	while (a[j]>m) do dec(j);
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
  randomize;
  readln(n);
  for i:=1 to n do
    read(a[i]);
  readln;
  qsort(1,n);
  tot:=1;
  x:=a[1];y:=-1;z:=-1;
  for i:=2 to n do
	if (a[i]<>a[i-1]) and (tot<=3) then
	begin
	  inc(tot);
	  if (x=-1) then x:=a[i] else 
		if (y=-1) then y:=a[i] else z:=a[i];
	end;
  if (tot>=4) then writeln('NO') else
  begin
    if (tot<=2) then writeln('YES') else
	begin
	  if (z-y=y-x) then writeln('YES') else writeln('NO');
	end;
  end;
end.
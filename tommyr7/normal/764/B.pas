var n,i,t:longint;
    a:array[0..2000007] of longint;
begin
  readln(n);
  for i:=1 to n do
	read(a[i]);
  readln;
  for i:=1 to n div 2 do
	if (i mod 2=1) then
    begin
	  t:=a[i];
	  a[i]:=a[n-i+1];
	  a[n-i+1]:=t;
	end;
  for i:=1 to n do
	write(a[i],' ');
  writeln;
end.
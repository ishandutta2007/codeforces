var n,i,j:longint;
    a:array[0..100007] of int64;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    read(a[i]);
  readln;
  for i:=1 to n do
	write(a[i]+a[i+1],' ');
  writeln;
end.
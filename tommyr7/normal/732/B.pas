var n,k,i,ans:longint;
    f:array[0..500] of longint;
begin
  readln(n,k);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
	read(f[i]);
  readln;
  ans:=0;
  for i:=2 to n do
  begin
    if (f[i]+f[i-1]<k) then
    begin
	  ans:=ans+k-f[i]-f[i-1];
	  f[i]:=k-f[i-1];
	end;
  end;
  writeln(ans);
  for i:=1 to n do
	write(f[i],' ');
  writeln;
end.
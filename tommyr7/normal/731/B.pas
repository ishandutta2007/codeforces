var n,i,j:longint;
    f:array[0..200007] of longint;
begin
  readln(n);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
	read(f[i]);
  readln;
  for i:=1 to n-1 do
  begin
    if (f[i]<0) then
	begin
	  writeln('NO');
	  halt;
	end;
    f[i]:=f[i] mod 2;
    if (f[i]=1) then
    begin
	  f[i]:=f[i]-1;
	  f[i+1]:=f[i+1]-1;
	end;
  end;
  if (f[n]>=0) and (f[n] mod 2=0) then writeln('YES') else writeln('NO');
end.
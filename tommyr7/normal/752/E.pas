var n,k,i,j,x:longint;
    a,b:array[0..10000007] of int64;
	ans:int64;
begin
  readln(n,k);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
  begin
    read(x);
    inc(a[x]);
  end;
  readln;
  ans:=0;
  for i:=10000000 downto 1 do
  begin
    ans:=ans+a[i]-b[i];
    if (ans>=k) then
    begin
	  writeln(i);
	  halt;
	end;
	a[i div 2]:=a[i div 2]+a[i];
	a[i-i div 2]:=a[i-i div 2]+a[i];
	b[i-i div 2]:=b[i-i div 2]+a[i];
  end;
  writeln(-1);
end.
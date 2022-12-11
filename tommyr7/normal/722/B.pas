var n,i,j,tot:longint;
    a:array[0..200] of longint;
	s:string;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
	read(a[i]);
  readln;
  for i:=1 to n do
  begin
    readln(s);
    tot:=0;
    for j:=1 to length(s) do
		if (s[j]='a') or (s[j]='e') or (s[j]='i') or (s[j]='o') or (s[j]='u') or (s[j]='y') then inc(tot);
	if (tot<>a[i]) then
	begin
	  writeln('NO');
	  halt;
	end;
  end;
  writeln('YES');
end.
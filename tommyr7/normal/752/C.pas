var n,i,j,a,b,c,d,ans:longint;
    ch:array[0..200007]of char;
procedure deal(x:char);
begin
  if (x='L') then inc(a);
  if (x='U') then inc(b);
  if (x='R') then inc(c);
  if (x='D') then inc(d);
end;
begin
  readln(n);
  for i:=1 to n do
	read(ch[i]);
  ans:=1;
  a:=0;
  b:=0;
  c:=0;
  d:=0;
  deal(ch[1]);
  for i:=2 to n do
  begin
    deal(ch[i]);
    if ((a>0) and (c>0)) or ((b>0) and (d>0)) then
    begin
	  a:=0;b:=0;c:=0;d:=0;
	  inc(ans);
	  deal(ch[i]);
	end;
  end;
  writeln(ans);
end.
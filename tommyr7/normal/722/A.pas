var n,i,j,a,b:longint;
    s:string;
begin
  readln(n);
  readln(s);
  a:=(ord(s[1])-48)*10+ord(s[2])-48;
  b:=(ord(s[4])-48)*10+ord(s[5])-48;
  if (n=24) then
  begin
    if not((0<=a) and (a<=23)) then a:=10+(a mod 10);
	if not((0<=b) and (b<=59)) then b:=b mod 10;
	if (0<=a) and (a<=9) then write('0');
	write(a);
	write(':');
	if (0<=b) and (b<=9) then write('0');
	writeln(b);
  end
  else
  begin
    if not((1<=a) and (a<=12)) then
		if (a mod 10<>0) then a:=(a mod 10) else a:=10;
	  	if not((0<=b) and (b<=59)) then b:=b mod 10;
	if (0<=a) and (a<=9) then write('0');
	write(a);
	write(':');
	if (0<=b) and (b<=9) then write('0');
	writeln(b);
	end;
end.
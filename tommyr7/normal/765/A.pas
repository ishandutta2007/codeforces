var n,i,j,tot1,tot2:longint;
    s,s1,s2:string;
	ch:char;
begin
  readln(n);
  readln(s);
  tot1:=0;tot2:=0;
  for i:=1 to n do
  begin
    s1:='';s2:='';
    for j:=1 to 3 do
	begin
	  read(ch);
	  s1:=s1+ch;
	end;
	read(ch);read(ch);
	for j:=1 to 3 do
	begin
	  read(ch);
	  s2:=s2+ch;
	end;
	if (s1=s) then inc(tot1);
	if (s2=s) then inc(tot2);
	readln;
  end;
  if (tot1=tot2) then writeln('home') else writeln('contest');
end.
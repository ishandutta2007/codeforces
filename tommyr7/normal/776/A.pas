var n,i,j:longint;
    s1,s2,ss1,ss2:string;
	ch:char;
begin
  s1:='';s2:='';read(ch);
  while (ch<>' ') do
  begin
    s1:=s1+ch;read(ch);
  end;
  readln(s2);
  readln(n);
  writeln(s1,' ',s2);
  for i:=1 to n do
  begin
      ss1:='';ss2:='';read(ch);
  while (ch<>' ') do
  begin
    ss1:=ss1+ch;read(ch);
  end;
  readln(ss2);
  if (ss1=s1) then s1:=ss2 else if (ss1=s2) then s2:=ss2;
  writeln(s1,' ',s2);
  end;
end.
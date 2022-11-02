var
  s,a,b,c:extended;

begin
  read(s,a,b,c);
  if (a=0)and(b=0)and(c=0)then begin
    writeln(s:0:10,' 0 0');
    exit;
  end;
  s:=s/(a+b+c);
  writeln(a*s:0:10,' ',b*s:0:10,' ',c*s:0:10);
end.
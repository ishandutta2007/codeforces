const
  inf=1000000000;

var
  s,p:ansistring;
  res,cr,i,j:longint;

begin
  readln(s);
  readln(p);
  for i:=1 to length(p)do s:='!'+s+'!';
  res:=inf;
  for i:=1 to length(s)-length(p)+1do begin
    cr:=0;
    for j:=i to i+length(p)-1 do
      inc(cr,ord(s[j]<>p[j-i+1]));
    if (cr<res)then res:=cr;
  end;
  writeln(res);
end.
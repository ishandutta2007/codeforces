var                                                                  
  a,b:ansistring;
  i:longint;

begin
  readln(a);
  readln(b);
  for i:=1 to length(a)do a[i]:=upcase(a[i]);
  for i:=1 to length(b)do b[i]:=upcase(b[i]);
  if (a=b)then writeln(0)else if (a<b)then writeln(-1)else writeln(1);
end.
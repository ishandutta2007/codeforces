const
  ABC='><+-.,[]';
var
  res,i:longint;
  s:ansistring;
    
begin
  readln(s);
  res:=0;
  for i:=1 to length(s)do res:=(res*16+7+pos(s[i],ABC))mod 1000003;
  writeln(res);
end.
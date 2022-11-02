var
  kt,res,i:longint;
  s:ansistring;

begin
  readln(s);
  s:=s+'!';
  kt:=1;
  res:=0;
  for i:=1 to length(s)-1 do
    if (s[i]<>s[i+1])then begin
      inc(res,(kt+4)div 5);
      kt:=1;
    end else inc(kt);
  writeln(res);
end.
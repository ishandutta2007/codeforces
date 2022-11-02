var
  s:ansistring;
  k,res,i:longint;
begin
  readln(s);
  k:=0;
  res:=length(s);
  for i:=1 to length(s)do 
    if (s[i]='(')
      then inc(k)
      else begin
        if (k=0)then dec(res)else dec(k);
      end;
  writeln(res-k);
end.
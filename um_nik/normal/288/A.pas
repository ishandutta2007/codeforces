var n,i,k:integer;
s:string;
begin
readln(n,k);
s:='';
if (n=1) and (k=1) then writeln('a') else
begin
if (k>n) or (k=1) then writeln(-1) else
  begin
  for i:=1 to n-k do s+=chr(98-i mod 2);
  if (n-k) mod 2=0 then s+='ab' else s+='ba';
  for i:=3 to k do s+=chr(96+i);
  writeln(s);
  end;
end;
end.
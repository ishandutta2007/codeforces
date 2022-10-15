var
  n,i:longint;
  a:array[1..1000] of longint;
begin
  readln(n);
  if not odd(n) then
  write('No')
   else
   begin
     for i:=1 to n do
      read(a[i]);
     if (odd(a[1])) and (odd(a[n])) then
     write('Yes')
      else write('No')
   end
end.
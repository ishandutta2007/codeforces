var
  s:string;
  k,n,i:longint;
  a:array['a'..'z'] of boolean;
begin
  readln(s);
  read(k);
  if k>length(s) then
  begin
    write('impossible');
    halt
  end;
  for i:=1 to length(s) do
   if not a[s[i]] then
   begin
     inc(n);
     a[s[i]]:=true
   end;
  if n>=k then
  write(0)
   else write(k-n)
end.
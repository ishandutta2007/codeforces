var s: string;
    n, k: longint;

begin
 readln(n);
 if n >= 0 then writeln(n)
 else
  begin
   str(n, s);
   k:=length(s);
   if s[k] > s[k-1] then delete(s, k, 1)
   else delete(s, k-1, 1);
   if s = '-0' then s:='0';
   writeln(s); 
  end;
end.
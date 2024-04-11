var
  c:char;
  n:longint absolute c;

begin
  while not eoln do
    begin
      read(c);
      if c in ['A','O','Y','E','U','I','a','o','y','e','u','i']
        then continue;
      write('.');
      if c in ['A'..'Z'] then
        dec(n, ord('A')-ord('a'));
      write(c)
    end
end.
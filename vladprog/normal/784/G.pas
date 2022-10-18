var
  s:string;
  c:char;
  res,sign,i,n:longint;

begin
  res:=0;
  sign:=1;
  repeat
    s:='';
    c:='0';
    repeat
      s:=s+c;
      read(c)
    until (c='+') or (c='-') or eoln;
    if (c<>'+') and (c<>'-') then
      s:=s+c;
    val(s,n,i);
    res:=res+n*sign;
    if c='+'
      then sign:=1
      else sign:=-1
  until eoln;
  str(res,s);
  for n:=1 to length(s) do
    begin
      for i:=1 to ord(s[n]) do
        write('+');
      write('.');
      write('>')
    end
end.
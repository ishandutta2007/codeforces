var
  n,last,i,st:longint;
  s:ansistring;
  ch:char;

begin
  readln(s);
  n:=length(s);
  st:=1;
  while (st<=n)do begin
    ch:='a';
    for i:=st to n do 
      if (s[i]>ch)then ch:=s[i];
    for i:=st to n do 
      if (s[i]=ch)then begin
        last:=i;
        write(ch);
      end;
    st:=last+1;
  end;
  writeln;
end.
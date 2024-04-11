{$r-,q-,s-,i-,o+}
var
  ch:char;
  sb,sn:ansistring;
  n,b,c,cr,rb:int64;
  j,i:longint;
begin
  read(ch);
  sb:='';
  while (ch in['0'..'9'])do begin
    sb:=sb+ch;
    read(ch);
  end;
  while (ch=' ')do read(ch);
  sn:='';
  while (ch in['0'..'9'])do begin
    sn:=sn+ch;
    read(ch);
  end;
  readln(c);
  b:=0;
  for i:=1 to length(sb)do b:=(b*10+ord(sb[i])-48)mod c;
  for i:=length(sn)downto 1 do 
    if (sn[i]='0')then sn[i]:='9'else begin
      sn[i]:=chr(ord(sn[i])-1);
      break;
    end;
  cr:=(b+c-1)mod c;
  for i:=length(sn)downto 1 do begin
    rb:=1;
    for j:=1 to ord(sn[i])-48 do rb:=rb*b mod c;
    cr:=cr*rb mod c;
    rb:=1;
    for j:=1 to 10 do rb:=rb*b mod c;
    b:=rb;
  end;
  if (cr=0)then cr:=c;
  writeln(cr);
end.
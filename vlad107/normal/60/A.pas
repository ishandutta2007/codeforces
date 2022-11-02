uses math;
var
  i,n,m,r,l,x:longint;
  ch:char;
  s:string;
begin
  readln(r,m);
  l:=1;
  for i:=1 to m do begin
    read(ch);
    while (ch<>'T')do read(ch);
    s:='';
    while not (ch in['0'..'9'])do begin
      s:=s+ch;
      read(ch);
    end;
    x:=0;
    while (ch in ['0'..'9'])do begin
      x:=x*10+ord(ch)-48;
      read(ch);
    end;
    if (s[8]='l')
      then r:=min(r,x-1)
      else l:=max(l,x+1);
  end;
  if (r<l)
    then writeln(-1)
    else writeln(r-l+1);
end.
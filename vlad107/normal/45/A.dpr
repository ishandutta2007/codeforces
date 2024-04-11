const
  t:array[1..12]of string=('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December');
var
  x,i:longint;
  s:string;
begin
  readln(s);
  readln(x);
  x:=x mod 12;
  for i:=1 to 12 do begin
    if (t[i]<>s)then continue;
    x:=x+i;
    if (x>12)then dec(x,12);
    writeln(t[x]);
    exit;
  end;
end.
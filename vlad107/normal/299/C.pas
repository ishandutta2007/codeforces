var
  a,b:ansistring;
  x1,x2,x3,x4,n,i:longint;

begin
  readln(n);
  readln(a);
  readln(b);
  for i:=1 to 2*n do 
    if (a[i]='0')and(b[i]='0')then inc(x1)else
    if (a[i]='0')and(b[i]='1')then inc(x2)else
    if (a[i]='1')and(b[i]='0')then inc(x3)else
    inc(x4);
  a:='';b:='';
  for i:=1 to n do begin
    if (x4>0)then begin a:=a+'1';dec(x4);end else
    if (x3>0)then begin a:=a+'1';dec(x3);end else
    if (x2>0)then begin a:=a+'0';dec(x2);end else
    if (x1>0)then begin a:=a+'0';dec(x1);end;
    
    if (x4>0)then begin b:=b+'1';dec(x4);end else
    if (x2>0)then begin b:=b+'1';dec(x2);end else
    if (x3>0)then begin b:=b+'0';dec(x3);end else
    if (x1>0)then begin b:=b+'0';dec(x1);end;
  end;
  if (a>b)then writeln('First')else
  if (b>a)then writeln('Second')else
  writeln('Draw');
end.
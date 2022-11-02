var
  r1,r2,c1,c2,d1,d2,a,b,c,d:longint;

begin
  read(r1,r2,c1,c2,d1,d2);
  for a:=1 to 9 do begin
    b:=r1-a;
    c:=c1-a;
    d:=d1-a;
    if (b=a)or(c=a)or(d=a)or(c=b)or(d=b)or(d=c)then continue;
    if (b<1)or(c<1)or(d<1)or(b>9)or(c>9)or(d>9)then continue;
    if (a+b<>r1)or(a+c<>c1)or(a+d<>d1)or
       (c+d<>r2)or(b+d<>c2)or(b+c<>d2)then continue;
    writeln(a,' ',b);
    writeln(c,' ',d);
    exit;
  end;
  writeln(-1);
end.
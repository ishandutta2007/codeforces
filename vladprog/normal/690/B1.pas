uses math;

var
  n,i,j,x1,x2,y1,y2,xx1,xx2,yy1,yy2:longint;
  a:array[1..50,1..50]of char;

function tester(x,y,x1,x2,y1,y2:longint):char;
begin
  if ((x=x1-1)or(x=x2+1))and((y=y1-1)or(y=y2+1))
    then tester:='1'
    else if (x>=x1-1)and(x<=x2+1)and(y>=y1-1)and(y<=y2+1)
      then if (x=x1-1)or(x=x2+1)or(y=y1-1)or(y=y2+1)
        then tester:='2'
        else tester:='4'
      else tester:='0'
end;

procedure prov(x1,x2,y1,y2:longint);
var
  i,j:longint;
begin
//  writeln('(',x1,';',y1,') (',x2,';',y2,')');
  for i:=1 to n do
    begin
      for j:=1 to n do
        begin
//          write(tester(i,j,x1,x2,y1,y2));
          if a[i,j]<>tester(i,j,x1,x2,y1,y2)
            then exit // write('! ')
//            else write('  ')
        end;
//      writeln
    end;
  writeln('Yes');
  halt
end;

begin
  readln(n);
  x1:=n;
  y1:=n;
  x2:=1;
  y2:=1;
  for i:=1 to n do
    begin
      for j:=1 to n do
        begin
          read(a[i,j]);
          if a[i,j]<>'0' then
            begin
              x1:=min(x1,i);
              x2:=max(x2,i);
              y1:=min(y1,j);
              y2:=max(y2,j)
            end
        end;
      readln
    end;
  for xx1:=x1 to x1+1 do
    for xx2:=x2 downto x2-1 do
      for yy1:=y1 to y1+1 do
        for yy2:=y2 downto y2-1 do
          prov(xx1,xx2,yy1,yy2);
  writeln('No')
end.
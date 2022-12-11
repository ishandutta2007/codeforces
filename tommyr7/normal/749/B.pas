var x,y:array[1..3] of longint;
    i,j,xx,yy:longint;
begin
  writeln(3);
  xx:=0;yy:=0;
  for i:=1 to 3 do
  begin
    readln(x[i],y[i]);
    xx:=xx+x[i];
    yy:=yy+y[i];
  end;
  for i:=1 to 3 do
	  writeln(xx-x[i]-x[i],' ',yy-y[i]-y[i]);
end.
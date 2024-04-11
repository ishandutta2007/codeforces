var
  x1,y1,x2,y2,x3,y3,t:int64;

begin
  read(x1,y1,x2,y2,x3,y3);
  t:=(y2-y1)*(x3-x1)+(x1-x2)*(y3-y1);
  if (t>0)then writeln('RIGHT')else
  if (t<0)then writeln('LEFT')else
  writeln('TOWARDS');
end.
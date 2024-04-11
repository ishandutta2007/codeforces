var
  x,y,d:longint;
begin
  read(x,y);
  d:=trunc(sqrt(x*x+y*y));
  if (x*y<0)then begin
    if (d*d=x*x+y*y)or(d and 1=1)
      then writeln('black')
      else writeln('white');
  end else begin
    if (d*d=x*x+y*y)or(d and 1=0)
      then writeln('black')
      else writeln('white');
  end;
end.
var
  i,j,n,m,x,sx,sy,ex,ey,res:longint;
begin
  read(n,m,x);
  sx:=x;sy:=x;
  ex:=n-x+1;ey:=m-x+1;
  res:=0;
  for i:=sx to ex do for j:=sy to ey do begin
    if (i<>sx)and(i<>ex)and(j<>sy)and(j<>ey)then continue;
    inc(res,1-((i+j)and 1));
  end;
  writeln(res);
end.
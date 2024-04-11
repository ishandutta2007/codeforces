var
  x,y,res,cr,i,n:longint;

begin
  read(n);
  res:=0;
  cr:=0;
  for i:=1 to n do begin
    read(x,y);cr:=cr-x+y;
    if (cr>res)then res:=cr;
  end;
  writeln(res);
end.
var z,x,y,m,ans,k:int64;
begin
read(x,y,m);
ans:=0;
if x>y then
  begin
  z:=x;
  x:=y;
  y:=z;
  end;
if y>=m then
  begin
  writeln(0);
  halt;
  end;
if y<=0 then
  begin
  writeln(-1);
  halt;
  end;
while y<m do
  begin
  z:=y-x;
  k:=(z div y)+1;
  ans+=k;
  z:=y;
  y:=x+k*y;
  x:=z;
  end;
writeln(ans);
end.
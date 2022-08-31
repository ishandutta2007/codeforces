{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  m1,m2,t1,t2,x1,x2,t0,y1,y2,z1,z2,max,a,b: int64;

procedure go(y1,y2:int64);
var
  d1,d2: int64;
begin
  d1:=t1*y1+t2*y2-t0*y1-t0*y2;
  d2:=y1+y2;
  if d1 < 0 then exit;
  if (d1*m2 < m1*d2) or (d1*m2 = m1*d2) and (y1+y2 > max) then
  begin
    m1:=d1;
    m2:=d2;
    max:=y1+y2;
    z1:=y1; z2:=y2;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(t1,t2,x1,x2,t0);
  m1:=1; m2:=0;
  max:=-1;
  z1:=0; z2:=0;
  go(0,x2);
  y1:=1;
  while y1 <= x1 do
  begin
    a:=t2-t0;
    b:=y1*(t0-t1);
    // a*y2 >= b
    if a > 0 then
    begin
      y2:=(b+a-1) div a;
      if y2 <= x2 then go(y1,y2);
    end
    else go(y1,x2);
    inc(y1);
  end;
  writeln(z1,' ',z2);
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  xa,ya,xb,yb,xc,yc: int64;

procedure wr;
begin
  writeln('YES');
  halt;
end;

procedure go(x1,y1,x,y:int64);
begin
  if (x = 0) and (y = 0) then
  begin
    if (x1 = 0) and (y1 = 0) then wr;
    exit;
  end;
  if ((x*x1+y*y1) mod (x*x+y*y) = 0) and ((x*y1-x1*y) mod (x*x+y*y) = 0) then wr;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(xa,ya,xb,yb,xc,yc);
  go(xb-xa,yb-ya,xc,yc);
  go(xb-ya,yb+xa,xc,yc);
  go(xb+xa,yb+ya,xc,yc);
  go(xb+ya,yb-xa,xc,yc);
  writeln('NO');
  close(input);
  close(output);
end.
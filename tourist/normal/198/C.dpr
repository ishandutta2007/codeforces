{$R-,S-,Q-,I-,O+}
const pi = 3.1415926535897932384626433832795;
var
  it,xp,yp,vp,x,y,v,r: longint;
  ll,rr,t,ang,xx,yy: extended;

function findang(x,y:extended):extended;
var
  ang: extended;
begin
  if abs(x) < 1e-9 then
  begin
    if y > 0 then findang:=0.5*pi
    else findang:=1.5*pi;
  end else
  if abs(y) < 1e-9 then
  begin
    if x > 0 then findang:=0
    else findang:=pi;
  end else
  begin
    ang:=arctan(abs(y/x));
    if (x < 0) and (y > 0) then ang:=pi-ang else
    if (x < 0) and (y < 0) then ang:=pi+ang else
    if (x > 0) and (y < 0) then ang:=2*pi-ang;
    findang:=ang;
  end;
end;

function dst(x,y:extended):extended;
var
  min: extended;
begin
  min:=abs(x-y);
  if abs(x+2*pi-y) < min then min:=abs(x+2*pi-y);
  if abs(x-2*pi-y) < min then min:=abs(x-2*pi-y);
  if abs(x+4*pi-y) < min then min:=abs(x+4*pi-y);
  if abs(x-4*pi-y) < min then min:=abs(x-4*pi-y);
  dst:=min;
end;

function go(x1,y1,x2,y2:extended):extended;
var
  ma,c1,c2,u1,u2,r1,r2,q1,q2,q3,q4,a,b,c,d,dist,d1,d2: extended;
  ok: boolean;
begin
  dist:=sqrt(sqr(x1-x2)+sqr(y1-y2));
  if dist < 1e-9 then
  begin
    go:=dist;
    exit;
  end;
  d1:=sqrt(sqr(x1)+sqr(y1));
  d2:=sqrt(sqr(x2)+sqr(y2));
  ok:=False;
  if d1*d1 > d2*d2+dist*dist then ok:=True;
  if d2*d2 > d1*d1+dist*dist then ok:=True;
  if not ok then
  begin
    a:=y2-y1; b:=x1-x2;
    c:=-a*x1-b*y1;
    d:=abs(c)/sqrt(a*a+b*b);
    if d < r then
    begin
      c1:=sqrt(x1*x1+y1*y1-r*r);
      c2:=sqrt(x2*x2+y2*y2-r*r);
      u1:=findang(x1,y1);
      u2:=findang(x2,y2);
      r1:=arctan(c1/r);
      q1:=u1-r1; q2:=u1+r1;
      r2:=arctan(c2/r);
      q3:=u2-r2; q4:=u2+r2;
      ma:=dst(q1,q3);
      if dst(q1,q4) < ma then ma:=dst(q1,q4);
      if dst(q2,q3) < ma then ma:=dst(q2,q3);
      if dst(q2,q4) < ma then ma:=dst(q2,q4);
      dist:=c1+c2+ma*r;
    end;
  end;
  go:=dist;
end;

begin
  read(xp,yp,vp);
  read(x,y,v,r);
  ll:=0; rr:=1e9;
  for it:=1 to 500 do
  begin
    t:=(ll+rr)*0.5;
    ang:=t*vp/sqrt(xp*xp+yp*yp);
    xx:=xp*cos(ang)-yp*sin(ang);
    yy:=xp*sin(ang)+yp*cos(ang);
    if go(x,y,xx,yy) <= t*v then rr:=t
    else ll:=t;
  end;
  writeln((ll+rr)*0.5:0:17);
end.
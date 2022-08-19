{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  ax,ay,az,vx,vy,vz,rb: int64;
  ox,oy,oz,r: array [0..111] of int64;
  m: array [0..111] of longint;
  px,py,pz: array [0..111,0..111] of int64;
  ans: extended;
  n,i,j: longint;

procedure check(x,y,z,q:int64);
var
  a,b,c,d: int64;
  u: extended;
begin
  a:=vx*vx+vy*vy+vz*vz;
  b:=-2*(x*vx+y*vy+z*vz);
  c:=x*x+y*y+z*z-q*q;
  d:=b*b-4*a*c;
  if d < 0 then exit;
  u:=(-b-sqrt(1.0*d))/(2*a);
  if u > 0 then
    if u < ans then ans:=u;
  u:=(-b+sqrt(1.0*d))/(2*a);
  if u > 0 then
    if u < ans then ans:=u;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(ax,ay,az,vx,vy,vz,rb,n);
  for i:=1 to n do
  begin
    read(ox[i],oy[i],oz[i],r[i],m[i]);
    ox[i]:=ox[i]-ax;
    oy[i]:=oy[i]-ay;
    oz[i]:=oz[i]-az;
    for j:=1 to m[i] do
    begin
      read(px[i,j],py[i,j],pz[i,j]);
      px[i,j]:=px[i,j]+ox[i];
      py[i,j]:=py[i,j]+oy[i];
      pz[i,j]:=pz[i,j]+oz[i];
    end;
  end;
  ans:=1e20;
  for i:=1 to n do
  begin
    check(ox[i],oy[i],oz[i],r[i]+rb);
    for j:=1 to m[i] do check(px[i,j],py[i,j],pz[i,j],rb);
  end;
  if ans > 1e18 then writeln(-1)
  else writeln(ans:0:17);
  close(input);
  close(output);
end.
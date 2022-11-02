const
  eps=1e-8;
  inf=1e9;

var
  a,b,m,x,y,z,vx,vy,vz,tt:extended;

  procedure check(time:extended);
    begin
      if (time<eps)then exit;
      if (time<tt)then tt:=time;
    end;

begin
  read(a,b,m);
  read(vx,vy,vz);
  x:=a/2;y:=m;z:=0;
  while (abs(y)>eps)do begin
    tt:=inf;
    if (vx<>0)then check(-x/vx);
    if (vy<>0)then check(-y/vy);
    if (vz<>0)then check(-z/vz);
    if (vz<>0)then check((b-z)/vz);
    if (vx<>0)then check((a-x)/vx);
    x:=x+vx*tt;
    y:=y+vy*tt;
    z:=z+vz*tt;
    if (abs(x)<eps)or(abs(x-a)<eps)then vx:=-vx;
    if (abs(z)<eps)or(abs(z-b)<eps)then vz:=-vz;
  end;
  writeln(x:0:10,' ',z:0:10);
end.
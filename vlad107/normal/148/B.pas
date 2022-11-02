const
  eps=1e-9;

var
  tt,vp,vd,t,f,c,x:extended;
  ans:longint;

begin
  read(vp,vd,t,f,c);
  x:=0;
  ans:=0;
  while (true)do begin
    x:=x+vp*t;
    if (x-c>-eps)then break;
    if (vp-vd>-eps)then break;
    //x+vp*tt=vd*tt
    tt:=x/(vd-vp);
    x:=x+tt*vp;
    if (x-c>-eps)then break;
    inc(ans);
    t:=f+x/vd;
  end;
  writeln(ans);
end.
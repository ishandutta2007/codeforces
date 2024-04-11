{$R-,S-,Q-,I-,O+}
const eps = 1e-9;
var
  x1u,x2u,x1d,x2d: array [0..4010] of extended;
  ans,area: extended;
  x,y,z,xx,yy: array [0..111] of extended;
  ii,j,m,n,h,f,i: longint;

procedure cut(x1,y1,x2,y2:extended);
var
  a,b,c,aa,bb,cc,d,dx,dy: extended;
  mm,i: longint;
begin
  a:=y2-y1;
  b:=x1-x2;
  c:=-a*x1-b*y1;
  x[m+1]:=x[1];
  y[m+1]:=y[1];
  mm:=0;
  for i:=1 to m+1 do z[i]:=a*x[i]+b*y[i]+c;
  for i:=1 to m do
  begin
    if z[i] > -eps then
    begin
      inc(mm);
      xx[mm]:=x[i];
      yy[mm]:=y[i];
    end;
    if (z[i] < -eps) and (z[i+1] > -eps) or (z[i] > -eps) and (z[i+1] < -eps) then
    begin
      aa:=y[i+1]-y[i];
      bb:=x[i]-x[i+1];
      cc:=-aa*x[i]-bb*y[i];
      d:=a*bb-b*aa;
      dx:=(b*cc-c*bb)/d;
      dy:=(c*aa-a*cc)/d;
      inc(mm);
      xx[mm]:=dx;
      yy[mm]:=dy;
    end;
  end;
  m:=mm;
  for i:=1 to m do
  begin
    x[i]:=xx[i];
    y[i]:=yy[i];
  end;
end;

begin
  read(n,h,f);
  for i:=1 to n do
  begin
    read(x1u[i],x2u[i]);
    x1d[i]:=x1u[i]*f/(f-h);
    x2d[i]:=x2u[i]*f/(f-h);
    x1d[i+n]:=x1d[i];
    x2d[i+n]:=x2d[i];
    x1u[i+n]:=x1d[i+n]*(f+h)/f;
    x2u[i+n]:=x2d[i+n]*(f+h)/f;
  end;
  ans:=0;
  for i:=1 to n+n do ans:=ans+0.5*((x2u[i]-x1u[i])+(x2d[i]-x1d[i]))*h;
  for i:=1 to n do
    for j:=n+1 to n+n do
    begin
      m:=4;
      x[1]:=x1d[i];
      y[1]:=0;
      x[2]:=x1u[i];
      y[2]:=h;
      x[3]:=x2u[i];
      y[3]:=h;
      x[4]:=x2d[i];
      y[4]:=0;
      cut(x1d[j],0,x1u[j],h);
      cut(x2u[j],h,x2d[j],0);
      x[m+1]:=x[1];
      y[m+1]:=y[1];
      area:=0;
      for ii:=1 to m do area:=area+(x[ii]-x[ii+1])*(y[ii]+y[ii+1]);
      area:=0.5*abs(area);
      ans:=ans-area;
    end;
  writeln(ans*2:0:17);
end.
uses
  math;

const
  eps=1e-9;

var
  a,r1,r2:extended;
  n:longint;

begin
  read(n,r1,r2);
  if (r2>r1)then begin
    writeln('NO');
    exit;
  end;
  if (r2*2>r1)then begin
    if (n=1)then writeln('YES')else writeln('NO');
    exit;
  end;
  a:=arccos((4*r2*r2-2*(r1-r2)*(r1-r2))/(-2*(r1-r2)*(r1-r2)));
  a:=a*n;
  if (a<2*pi+eps)then writeln('YES')else writeln('NO');
end.
{$R-,S-,Q-,I-,O+}
{$M 50000000}
const pi = 3.1415926535897932384626433832795;
var
  ang,xc,yc,r: extended;
  n,m,mm,i,j,kr: longint;
  b: array [0..5555,0..11] of longint;
  x,y: array [0..5555] of extended;
  num,rr,ss,ff,pred,last: array [0..5555] of longint;
  used: array [0..5555] of boolean;

procedure add(xx,yy:extended);
begin
  inc(mm);
  x[mm]:=xx;
  y[mm]:=yy;
end;

procedure rec(v:longint);
var
  j: longint;
begin
  j:=last[v];
  while j > 0 do
  begin
    last[v]:=pred[j];
    if not used[num[j]] then
    begin
      used[num[j]]:=True;
      rec(ff[j]);
    end;
    j:=pred[j];
  end;
  inc(kr);
  rr[kr]:=v;
end;

begin
  r:=sqrt(50/(1-cos(2*pi/5)));
  read(n);
  mm:=0; m:=0;
  add(0,0);
  for i:=1 to n do
  begin
    xc:=x[mm]; yc:=y[mm]-r;
    ang:=pi/2-2*pi/5; add(xc+cos(ang)*r,yc+sin(ang)*r);
    ang:=pi/2-4*pi/5; add(xc+cos(ang)*r,yc+sin(ang)*r);
    ang:=pi/2+2*pi/5; add(xc+cos(ang)*r,yc+sin(ang)*r);
    ang:=pi/2+4*pi/5; add(xc+cos(ang)*r,yc+sin(ang)*r);
    b[i,1]:=mm; b[i,2]:=mm-4; b[i,3]:=mm-2; b[i,4]:=mm-1; b[i,5]:=mm-3;
    b[i,6]:=b[i,1];
    for j:=1 to 5 do
    begin
      inc(m);
      ss[m]:=b[i,j];
      ff[m]:=b[i,j+1];
    end;
  end;
  writeln(mm);
  for i:=1 to mm do writeln(x[i]:0:17,' ',y[i]:0:17);
  for i:=1 to n do writeln(b[i,1],' ',b[i,4],' ',b[i,2],' ',b[i,5],' ',b[i,3]);
  for i:=1 to m do
  begin
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
    num[i+m]:=i;
    num[i]:=i;
  end;
  for i:=1 to m do used[i]:=False;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  kr:=0;
  rec(1);
  for i:=1 to kr-1 do write(rr[i],' ');
  writeln(rr[kr]);
end.
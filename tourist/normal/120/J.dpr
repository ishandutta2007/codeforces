{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const pi = 3.1415926535897932384626433832795;
      rng = 2.509;
var
  d,n,i,j,k1,k2,k3,k4,best: longint;
  len,ang: extended;
  x,y,z,w: array [0..100010] of longint;
  xx,yy: array [0..100010] of extended;

procedure Sort(l,r:longint);
var
  i,j,tt: longint;
  xt,tmp: extended;
begin
  i:=l; j:=r;
  xt:=xx[l+random(r-l+1)];
  repeat
    while xx[i] < xt do inc(i);
    while xt < xx[j] do dec(j);
    if i <= j then
    begin
      tmp:=xx[i]; xx[i]:=xx[j]; xx[j]:=tmp;
      tmp:=yy[i]; yy[i]:=yy[j]; yy[j]:=tmp;
      tt:=x[i]; x[i]:=x[j]; x[j]:=tt;
      tt:=y[i]; y[i]:=y[j]; y[j]:=tt;
      tt:=z[i]; z[i]:=z[j]; z[j]:=tt;
      tt:=w[i]; w[i]:=w[j]; w[j]:=tt;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randomize;
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(x[i],y[i]);
    z[i]:=1;
    if y[i] < 0 then
    begin
      y[i]:=-y[i];
      inc(z[i],2);
    end;
    if x[i] < 0 then
    begin
      x[i]:=-x[i];
      inc(z[i]);
    end;
    w[i]:=i;
  end;
  for i:=1 to n do
  begin
    if y[i] = 0 then ang:=0 else
    if x[i] = 0 then ang:=pi
    else ang:=arctan(y[i]/x[i]);
    len:=sqrt(x[i]*x[i]+y[i]*y[i]);
    xx[i]:=cos(ang+rng)*len;
    yy[i]:=sin(ang+rng)*len;
  end;
  Sort(1,n);
  best:=round(1e9);
  k1:=0; k2:=0; k3:=0; k4:=0;
  for i:=1 to n do
  begin
    j:=i+1;
    while (j <= n) and ((xx[j]-xx[i])*(xx[j]-xx[i]) < best) do
    begin
      d:=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      if d < best then
      begin
        best:=d;
        k1:=w[i]; k2:=z[i];
        k3:=w[j]; k4:=5-z[j];
      end;
      inc(j);
    end;
  end;
  writeln(k1,' ',k2,' ',k3,' ',k4);
  close(input);
  close(output);
end.
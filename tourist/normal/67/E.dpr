{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const eps = 1e-9;
var
  n,i: longint;
  ll,rr,a,b,c,xx: int64;
  x,y: array [0..2222] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(x[i],y[i]);
    inc(x[i],10);
    inc(y[i],10);
  end;
  x[n+1]:=x[1]; y[n+1]:=y[1];
  ll:=x[1]; rr:=x[2];
  if ll > rr then begin ll:=x[2]; rr:=x[1]; end;
  for i:=1 to n do
  begin
    a:=y[i+1]-y[i];
    b:=x[i]-x[i+1];
    c:=-a*x[i]-b*y[i];
    if a = 0 then
    begin
      if b*y[1]+c < 0 then
      begin
        ll:=rr+1;
        break;
      end;
    end else
    if a > 0 then
    begin
      xx:=trunc((-b*y[1]-c)/a+1-eps);
      if xx > ll then ll:=xx;
    end else
    begin
      xx:=trunc((-b*y[1]-c)/a+eps);
      if xx < rr then rr:=xx;
    end;
  end;
  if ll > rr then writeln(0)
  else writeln(rr-ll+1);
  close(input);
  close(output);
end.
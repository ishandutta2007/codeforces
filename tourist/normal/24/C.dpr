{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i: longint;
  u,p,t,mx,my,qx,qy: int64;
  x,y,z: array [0..200010] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,t,mx,my);
  for i:=1 to n do read(x[i],y[i]);
  for i:=1 to n do
  begin
    x[i+n]:=x[i];
    y[i+n]:=y[i];
  end;
  inc(n,n);
  u:=t mod n; p:=t div n;
  for i:=1 to u do z[i]:=p+1;
  for i:=u+1 to n do z[i]:=p;
  for i:=1 to n do
    if (i+u) and 1 = 1 then z[i]:=-z[i];
  qx:=0; qy:=0;
  for i:=1 to n do
  begin
    qx:=qx+int64(x[i])*z[i];
    qy:=qy+int64(y[i])*z[i];
  end;
  qx:=qx*2; qy:=qy*2;
  if t and 1 = 1 then dec(qx,mx)
  else inc(qx,mx);
  if t and 1 = 1 then dec(qy,my)
  else inc(qy,my);
  writeln(qx,' ',qy);
  close(input);
  close(output);
end.
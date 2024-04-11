{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  yy,zz,n,m,i,e: longint;
  lg,rg: array [0..2,0..1,0..110] of longint;
  kg: array [0..2,0..1] of longint;
  was: array [0..100010,0..2,0..1] of boolean;
  x,y,z,km: array [0..666666] of longint;

procedure put(x1,x2,yy,zz:longint);
var
  u1,u2,v,j,xx: longint;
begin
  if x2 < 0 then exit;
  if x1 > n then exit;
  zz:=1-zz;
  yy:=2-yy;
  if x1 < 0 then x1:=0;
  if x2 > n then x2:=n;
  xx:=x1; x1:=n-x2; x2:=n-xx;
  u1:=x1; u2:=x2;
  for v:=1 to kg[yy,zz] do
  begin
    if x1 < lg[yy,zz,v] then x1:=lg[yy,zz,v];
    if x2 > rg[yy,zz,v] then x2:=rg[yy,zz,v];
    for j:=x1 to x2 do
      if not was[j,yy,zz] then
      begin
        inc(e);
        x[e]:=j;
        y[e]:=yy;
        z[e]:=zz;
        km[e]:=km[i]+1;
        was[j,yy,zz]:=True;
      end;
    if x1 <= x2 then
      if (x1 > lg[yy,zz,v]) and (x2 < rg[yy,zz,v]) then
      begin
        inc(kg[yy,zz]);
        lg[yy,zz,kg[yy,zz]]:=x2+1;
        rg[yy,zz,kg[yy,zz]]:=rg[yy,zz,v];
        rg[yy,zz,v]:=x1-1;
      end else
      if x2 < rg[yy,zz,v] then lg[yy,zz,v]:=x2+1
      else rg[yy,zz,v]:=x1-1;
    x1:=u1; x2:=u2;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for yy:=0 to 2 do
    for zz:=0 to 1 do
    begin
      kg[yy,zz]:=1;
      lg[yy,zz,1]:=0;
      rg[yy,zz,1]:=n;
    end;
  fillchar(was,sizeof(was),False);
  i:=1; e:=1;
  x[1]:=n; y[1]:=2; z[1]:=0;
  km[1]:=0;
  was[n,2,0]:=True;
  while i <= e do
  begin
    if (x[i] = n) and (y[i] > 0) and (z[i] = 1) then
    begin
      writeln(km[i]);
      halt;
    end;
    if y[i] = 0 then
    begin
      put(x[i]-m,x[i]-1,0,z[i]);
    end else
    if y[i] = 1 then
    begin
      put(x[i]-(m shr 1),x[i]-1,1,z[i]);
      if (x[i] > 0) and (x[i] <= m) then put(x[i]-(m-x[i]),x[i],0,z[i]);
    end else
    begin
      put(x[i]-m,x[i]-1,2,z[i]);
      if (n-x[i]) <= m then
        if x[i] < n then put(x[i]-((m-(n-x[i])) shr 1),x[i],1,z[i])
        else put(x[i]-(m shr 1),x[i]-1,1,z[i]);
      if n <= m then put(x[i],x[i],0,z[i]);
    end;
    inc(i);
  end;
  writeln(-1);
  close(input);
  close(output);
end.
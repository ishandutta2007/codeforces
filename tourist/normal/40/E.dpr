{$R-,S-,Q-,I-,O+}
var
  n,m,k,i,j,x,y,z,t: longint;
  r,f: boolean;
  c,p: array [0..1010] of longint;
begin
  read(n,m);
  if n < m then
  begin
    i:=n; n:=m; m:=i;
    f:=True;
  end
  else f:=False;
  fillchar(c,sizeof(c),0);
  for i:=1 to n do p[i]:=1;
  read(k);
  for i:=1 to k do
  begin
    if f then read(y,x,z)
    else read(x,y,z);
    inc(c[x]);
    p[x]:=p[x]*z;
  end;
  read(t);
  x:=1; r:=False;
  for i:=1 to n do
    if (c[i] = 0) and (not r) then r:=True else
    if (c[i] = m) and (p[i] = 1) then x:=0 else
      for j:=1 to m-c[i]-1 do x:=(x*2) mod t;
  if (n+m) and 1 <> 0 then x:=0;
  writeln(x);
end.
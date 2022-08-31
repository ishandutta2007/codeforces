{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const dx: array [1..6] of longint = (-1,1,0,0,0,0);
      dy: array [1..6] of longint = (0,0,-1,1,0,0);
      dz: array [1..6] of longint = (0,0,0,0,-1,1);
var
  n,m,k,i,j,p,xk,yk,zk,e: longint;
  ch: char;
  x,y,z: array [0..33*33*33] of longint;
  a: array [0..33,0..33,0..33] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  for i:=1 to n do
    for j:=1 to m do
      for p:=1 to k do
      begin
        read(ch);
        while not (ch in ['.','#']) do read(ch);
        a[i,j,p]:=ch;
      end;
  i:=1; e:=1;
  x[1]:=1;
  read(y[1],z[1]);
  a[x[1],y[1],z[1]]:='#';
  while i <= e do
  begin
    for j:=1 to 6 do
    begin
      xk:=x[i]+dx[j];
      yk:=y[i]+dy[j];
      zk:=z[i]+dz[j];
      if (xk > 0) and (yk > 0) and (xk <= n) and (yk <= m) and (zk > 0) and (zk <= k) then
        if a[xk,yk,zk] = '.' then
        begin
          inc(e);
          x[e]:=xk;
          y[e]:=yk;
          z[e]:=zk;
          a[xk,yk,zk]:='#';
        end;
    end;
    inc(i);
  end;
  writeln(e);
  close(input);
  close(output);
end.
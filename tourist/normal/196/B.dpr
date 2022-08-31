{$R-,S-,Q-,I-,O+}
const dx: array [1..4] of longint = (0,1,0,-1);
      dy: array [1..4] of longint = (1,0,-1,0);
var
  n,m,i,j,e,xk,yk,nx,ny: longint;
  x,y: array [0..5000010] of longint;
  was: array [0..1510,0..1510] of boolean;
  qx,qy: array [0..1510,0..1510] of longint;
  a: array [0..1510,0..1510] of char;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  x[1]:=0; y[1]:=0;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] = 'S' then
      begin
        x[1]:=i;
        y[1]:=j;
      end;
  i:=1; e:=1;
  fillchar(was,sizeof(was),False);
  fillchar(qx,sizeof(qx),0);
  fillchar(qy,sizeof(qy),0);
  was[x[1],y[1]]:=True;
  while i <= e do
  begin
    for j:=1 to 4 do
    begin
      xk:=x[i]+dx[j];
      yk:=y[i]+dy[j];
      nx:=qx[x[i],y[i]];
      ny:=qy[x[i],y[i]];
      if xk = 0 then begin xk:=n; dec(nx); end;
      if yk = 0 then begin yk:=m; dec(ny); end;
      if xk = n+1 then begin xk:=1; inc(nx); end;
      if yk = m+1 then begin yk:=1; inc(ny); end;
      if a[xk,yk] = '#' then continue;
      if was[xk,yk] and ((qx[xk,yk] <> nx) or (qy[xk,yk] <> ny)) then
      begin
        writeln('Yes');
        halt;
      end;
      if not was[xk,yk] then
      begin
        inc(e);
        x[e]:=xk;
        y[e]:=yk;
        was[xk,yk]:=True;
        qx[xk,yk]:=nx;
        qy[xk,yk]:=ny;
      end;
    end;
    inc(i);
  end;
  writeln('No');
end.
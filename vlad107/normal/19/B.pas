{$r-,q-,s-,i-,o+}
const
  INF = 100000000000000000;

var
  nj, n, i, j : longint;
  res : int64;
  a, b : array [0..5000] of longint;
  f : array [0..2100, -2100..2100] of int64;

begin
 { assign(input, 'input.txt'); reset(input);
  assign(output, 'output.txt'); rewrite(output);}
  read(n);
  for i:=1 to n do read(a[i], b[i]);
  for i:=0 to n+1 do
    for j:=-n-1 to n+1 do
      f[i][j] := INF;
  f[1][0] := 0;
  for i:=1 to n do
    for j:=-n to n do begin
      if (f[i][j] = INF) then continue;
      nj := j + a[i];
      if (nj > n) then nj := n;
      if (f[i][j] + b[i] < f[i+1][nj])
        then f[i+1][nj] := f[i][j] + b[i];
      if (f[i+1][j-1] > f[i][j])
        then f[i+1][j-1] := f[i][j];
    end;
  res := INF;
  for i:=0 to n do
    if (f[n+1][i] < res)
      then res := f[n+1][i];
  writeln(res);
end.
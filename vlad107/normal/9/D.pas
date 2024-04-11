{$r-,q-,s-,i-,o+}
var
  res                : int64;
  n, h, qn, qh, i, j : longint;
  f                  : array [0..40, 0..40] of int64;

begin
  read(n, h);
  fillchar(f, sizeof(f), $0);
  f[0][0] := 1;
  f[1][1] := 1;
  for qh:=2 to n do
    for qn:=2 to n do begin
      for i:=0 to qn-1 do
        for j:=0 to qh-1 do
          f[qn][qh] := f[qn][qh] + f[i][j] * f[qn-i-1][qh-1];
      for i:=0 to qn-1 do
        for j:=0 to qh-2 do
          f[qn][qh] := f[qn][qh] + f[i][j] * f[qn-i-1][qh-1];
    end;
  res := 0;
  for i:=h to n do inc(res, f[n][i]);
  writeln(res);
end.
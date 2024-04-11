var
  n, k, xx, yy : int64;
  i : longint;
  x, y : array [0..1000000] of int64;

begin
  read(n, k);
  k := k mod (2*n);
  read(xx, yy);
  for i:=0 to n-1 do read(x[i], y[i]);
  for i:=1 to k do begin
    xx := x[(i-1) mod n]*2-xx;
    yy := y[(i-1) mod n]*2-yy;
  end;
  writeln(xx, ' ', yy);
end.
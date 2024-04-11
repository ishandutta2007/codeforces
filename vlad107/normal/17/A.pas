{$r-,q-,s-,i-,o+}
var
  n, k, m, i, j : longint;
  f, p : array [0..1000000] of boolean;
  a : array [0..1000000] of longint;

begin
  read(n, k);
  fillchar(p, sizeof(p), true);
  m := 0;
  fillchar(a, sizeof(a), false);
  for i:=2 to n do
    if (p[i]) then begin
      inc(m);
      a[m] := i;
      for j:=2 to n div i do p[i*j] := false;
    end;
  fillchar(f, sizeof(f), false);
  for i:=1 to m-1 do
    if (a[i]+a[i+1] < n) then
    f[a[i] + a[i+1] + 1] := true;
  for i:=2 to n do
    if (f[i]) and (p[i]) then
      dec(k);
  if (k<=0)
    then writeln('YES')
    else writeln('NO');
end.
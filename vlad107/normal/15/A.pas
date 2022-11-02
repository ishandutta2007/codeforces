{$r-,q-,s-,i-,o+}
var
  ok : boolean;
  res, n, t, i, j : longint;
  x, y : double;
  a, b : array [1..1111] of double;

begin
  read(n, t);
  for i:=1 to n do begin
    read(a[i], b[i]);
    x := a[i]-b[i]/2;
    y := a[i]+b[i]/2;
    a[i] := x;
    b[i] := y;
  end;
  res := 0;
  for i:=-4000 to 4000 do begin
    ok := true;
    x := i/2 - t/2;
    y := i/2 + t/2;
    for j:=1 to n do begin
      if (x <= a[j]) and (y > a[j]) then ok := false;
      if (x < b[j]) and (y >= b[j]) then ok := false;
      if (x >= a[j]) and (y <= b[j]) then ok := false;
      if (not ok) then break;
    end;
    if (not ok) then continue;
    ok := false;
    for j:=1 to n do
      if (y = a[j]) or (x = b[j]) then begin
        ok := true; break;
      end;
      if (ok) then inc(res);
  end;
  writeln(res);
end.
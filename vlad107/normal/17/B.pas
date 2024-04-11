{$r-,q-,s-,i-,o+}
var
  res, n, m, i : longint;
  x, y, z, nom : array [0..1000000] of longint;
  used : array [0..1000000] of boolean;

  procedure qs(l, r : longint);
    var
      i, j, x, tmp : longint;

    begin
      i := l; j := r;
      x := nom[(i+j) shr 1];
      while (i <= j) do begin
        while (z[nom[i]] < z[x]) do inc(i);
        while (z[nom[j]] > z[x]) do dec(j);
        if (i > j) then break;
        tmp := nom[i]; nom[i] := nom[j]; nom[j] := tmp;
        inc(i); dec(j);
      end;
      if (i < r) then qs(i, r);
      if (j > l) then qs(l, j);
    end;

begin
  read(n);
  for i:=1 to n do read(m);
  read(m);
  for i:=1 to m do begin
    read(x[i], y[i], z[i]);
  end;
  for i:=1 to m do nom[i] := i;
  qs(1, m);
  fillchar(used, sizeof(used), false);
  res := 0;
  for i:=1 to m do
    if (not used[y[nom[i]]]) then begin
      used[y[nom[i]]] := true;
      inc(res, z[nom[i]]);
    end;
  m := 0;
  for i:=1 to n do
    if (not used[i]) then inc(m);
  if (m > 1) then res := -1;
  writeln(res);
end.
{$r-,q-,s-,i-,o+}
const
  MAXN = 1111;
  INF = 1000100100;

var
  x0, y0, n, i, j, cx : longint;
  x, a, f1, f2 : array [1..MAXN, 1..MAXN] of longint;
  s : ansistring;

begin
//  assign(input, 'input.txt'); reset(input);
//  assign(output, 'output.txt'); rewrite(output);
  read(n);
  x0 := -1; y0 := -1;
  for i:=1 to n do for j:=1 to n do begin
    read(x[i][j]);
    if (x[i][j] = 0) then begin
      a[i][j] := INF;
      continue;
    end;
    a[i][j] := 0;
    cx := x[i][j];
    while (cx > 0) and (cx and 1 = 0) do begin
      cx := cx shr 1;
      inc(a[i][j]);
    end;
  end;
  for i:=1 to n do
    for j:=1 to n do f1[i][j] := INF;
  f1[1][1] := a[1][1];
  for i:=1 to n do
    for j:=1 to n do begin
      if (i = 1) and (j = 1) then continue;
      if (i > 1) then f1[i][j] := f1[i-1][j];
      if (j > 1) and (f1[i][j-1] < f1[i][j]) then f1[i][j] := f1[i][j-1];
      inc(f1[i][j], a[i][j]);
    end;
  for i:=1 to n do for j:=1 to n do begin
    if (x[i][j] = 0) then begin
      x0 := i; y0 := j;
      a[i][j] := INF;
      continue;
    end;
    a[i][j] := 0;
    cx := x[i][j];
    while (cx > 0) and (cx mod 5 = 0) do begin
      cx := cx div 5;
      inc(a[i][j]);
    end;
  end;
  for i:=1 to n do
    for j:=1 to n do f2[i][j] := INF;
  f2[1][1] := a[1][1];
  for i:=1 to n do
    for j:=1 to n do begin
      if (i = 1) and (j = 1) then continue;
      if (i > 1) then f2[i][j] := f2[i-1][j];
      if (j > 1) and (f2[i][j-1] < f2[i][j]) then f2[i][j] := f2[i][j-1];
      inc(f2[i][j], a[i][j]);
    end;
  if (x0 > 0) and (f1[n][n] > 1) and (f2[n][n] > 1) then begin
    writeln(1);
    for i:=2 to x0 do write('D');
    for i:=1 to n-1 do write('R');
    for i:=x0+1 to n do write('D');
    writeln;
    exit;
  end;
  if (f1[n][n] < f2[n][n]) then begin
    s := '';
    x0 := n; y0 := n;
    writeln(f1[n][n]);
    while (x0 > 1) or (y0 > 1) do
      if (x0 = 1) then begin
        s := 'R' + s;
        dec(y0);
      end else
      if (y0 = 1) then begin
        s := 'D' + s;
        dec(x0);
      end else
      if (f1[x0][y0-1] < f1[x0-1][y0]) then begin
        s := 'R' + s;
        dec(y0);
      end else begin
        s := 'D' + s;
        dec(x0);
      end;
    writeln(s);
  end else begin
    s := '';
    x0 := n; y0 := n;
    writeln(f2[n][n]);
    while (x0 > 1) or (y0 > 1) do
      if (x0 = 1) then begin
        s := 'R' + s;
        dec(y0);
      end else
      if (y0 = 1) then begin
        s := 'D' + s;
        dec(x0);
      end else
      if (f2[x0][y0-1] < f2[x0-1][y0]) then begin
        s := 'R' + s;
        dec(y0);
      end else begin
        s := 'D' + s;
        dec(x0);
      end;
    writeln(s);
  end;
end.
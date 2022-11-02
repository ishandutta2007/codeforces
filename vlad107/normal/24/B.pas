const
  ves : array [1..10] of longint = (25, 18, 15, 12, 10, 8, 6, 4, 2, 1);  

var
  s : string;
  x, t, n, ks, q, i : longint;
  k : array [1..1000] of longint;
  a : array [1..1000, 1..1000] of longint;
  ss : array [1..100000] of string;

  function cmp(x, y : longint) : boolean;
    var
      i : longint;

    begin
      i := 2;
      while (i <= 50) and (a[x][i] = a[y][i]) do inc(i);
      if (i > 50) then cmp := false else
      cmp := a[x][i] > a[y][i];
    end;

  function nom(s : string) : longint;
    var
      i : longint;

    begin
      i := 1;
      while (i <= ks) and (ss[i] <> s) do inc(i);
      if (i > ks) then begin
        inc(ks); ss[ks] := s;
      end;
      nom := i;
    end;

begin
  fillchar(k, sizeof(k), $0);
  ks := 0;
  readln(t);
  while (t > 0) do begin
    dec(t);
    readln(n);
    for i:=1 to n do begin
      readln(s);
      x := nom(s);
      inc(a[x][i]);
      if (i > 10) then continue;
      inc(k[x], ves[i]);
    end;
  end;
  q := 1;
  for i:=2 to ks do
    if (k[i] <> k[q]) then begin
      if (k[q] < k[i]) then q := i;
    end else begin
      if (a[q][1] <> a[i][1])
        then begin
          if (a[q][1] < a[i][1]) then q := i;
        end else begin
          if (cmp(i, q)) then q := i;
        end;
    end;
  writeln(ss[q]);
  q := 1;
  for i:=2 to ks do 
    if (a[q][1] <> a[i][1])
      then begin
        if (a[q][1] < a[i][1]) then q := i;
      end else
        if (k[i] <> k[q])
          then begin
            if (k[q] < k[i]) then q := i;
          end else begin
            if (cmp(i, q)) then q := i;
          end;
  writeln(ss[q]);
end.
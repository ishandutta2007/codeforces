var
  n, i, r1, r2 : longint;
  kg, a, b, c, d : array [0..1000000] of longint;
  g, p : array [1..300, 1..300] of longint;
  used : array [1..500] of boolean;

  procedure dfs(x : longint);
    var
      i : longint;

    begin
      used[x] := true;
      for i:=1 to kg[x] do begin
        if (a[p[x][i]] = x)
          then d[p[x][i]] := 0
          else d[p[x][i]] := 1;
        if (used[g[x][i]]) then continue;
        dfs(g[x][i]);
      end;
    end;

begin
  read(n);
  fillchar(kg, sizeof(kg), $0);
  for i:=1 to n do begin
    read(a[i], b[i], c[i]);
    inc(kg[a[i]]);
    g[a[i]][kg[a[i]]] := b[i];
    p[a[i]][kg[a[i]]] := i;
    inc(kg[b[i]]);
    g[b[i]][kg[b[i]]] := a[i];
    p[b[i]][kg[b[i]]] := i;
  end;
  fillchar(used, sizeof(used), false);
  dfs(1);
  r1 := 0;
  r2 := 0;
  for i:=1 to n do 
    if (d[i] = 0) then inc(r1, c[i]) else inc(r2, c[i]);
  if (r1 < r2) then writeln(r1) else writeln(r2);
end.
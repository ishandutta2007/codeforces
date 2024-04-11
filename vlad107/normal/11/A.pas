const
  MAXN = 2222;  

var
  t, i, res, d, n : longint;
  a               : array [1..MAXN] of longint;

begin
  read(n, d);              
  for i:=1 to n do read(a[i]);
  res := 0;
  for i:=2 to n do 
    if (a[i] <= a[i-1]) then begin
      t := (a[i-1] - a[i]) div d + 1;
      inc(res, t);
      a[i] := a[i] + t * d;
    end;
  writeln(res);
end.
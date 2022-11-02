{$r-,q-,s-,i-,o+}
const
  MAXN = 1111;  
  INF = 1e9;

var
  min : double;
  n, vb, vs, ex, ey, i, nom : longint;
  x   : array [1..MAXN] of longint;
  
  function dist(x1, y1, x2, y2 : double) : double;
    begin
      dist := sqrt(sqr(x1-x2) + sqr(y1-y2));
    end;

begin
  read(n, vb, vs);
  for i:=1 to n do read(x[i]);
  read(ex, ey);
  nom := 0;
  min := INF;
  for i:=2 to n do
    if (x[i] / vb + dist(x[i], 0, ex, ey) / vs <= min)
      then begin
        min := x[i] / vb + dist(x[i], 0, ex, ey) / vs;
        nom := i;
      end;
  writeln(nom);
end.
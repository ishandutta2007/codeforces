uses math;
const fi = '';
      fo = '';
      maxN = 500;
var n, i, j, u, v, x, t: longint;
    f: array [1..maxN, 1..maxN] of longint;
    a: array [1..maxN] of longint;
    res: array [1..maxN] of int64;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do
  for j:=1 to n do read(f[i, j]);
 for i:=1 to n do read(a[i]);

 for t:=n downto 1 do
  begin
   x:=a[t];
   for i:=t+1 to n do
    begin
     u:=a[i];
     for j:=t+1 to n do
      begin
       v:=a[j];
       if u = v then continue;
       f[x, u]:=min(f[x, u], f[x, v]+f[v, u]);
       f[u, x]:=min(f[u, x], f[u, v]+f[v, x]);
      end;
    end;

   for i:=t+1 to n do
    begin
     u:=a[i];
     for j:=t+1 to n do
      begin
       v:=a[j];
       if u = v then continue;
       f[u, v]:=min(f[u, v], f[u, x]+f[x, v]);
       f[v, u]:=min(f[v, u], f[v, x]+f[x, u]);
      end;
    end;

   for i:=t to n do
    for j:=t to n do res[t]:=res[t]+f[a[i], a[j]];
  end;

 for i:=1 to n do write(res[i], ' ');

 close(input); close(output);
end.
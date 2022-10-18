const fi = '';
      fo = '';
var i, j, k, n: longint;
    t, w: array [1..100] of longint;
    f: array [0..100, 0..200, 0..10000] of boolean;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do readln(t[i], w[i]);

 f[0, 0, 0]:=true;
 for i:=1 to n do
  for j:=0 to 200-t[i] do
   for k:=0 to 10000-w[i] do
    if f[i-1, j, k] = true then
     begin
      f[i, j+t[i], k]:=true;
      f[i, j, k+w[i]]:=true;
     end;

 for j:=0 to 200 do
  for k:=0 to j do
   if f[n, j, k] = true then
    begin
     writeln(j);
     close(input); close(output);
     halt;
    end;
end.
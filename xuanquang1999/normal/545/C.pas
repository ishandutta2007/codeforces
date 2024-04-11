const fi = '';
      fo = '';
      maxN = 100000;
var n, i, cur, cnt: longint;
    x, h: array [1..maxN] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do readln(x[i], h[i]);

 if n = 1 then writeln(1)
 else
  begin
   cnt:=2;
   cur:=x[1];
   for i:=2 to n-1 do
    if x[i]-h[i] > cur then
     begin
      inc(cnt);
      cur:=x[i];
     end
    else if x[i]+h[i] < x[i+1] then
     begin
      inc(cnt);
      cur:=x[i]+h[i];
     end
    else cur:=x[i];
   writeln(cnt);
  end;


 close(input); close(output);
end.
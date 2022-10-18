const fi = '';
      fo = '';
      maxN = 2000;
var x, y: array [1..maxN] of longint;
    n, k, i: longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, k);
 if n*(n-1) div 2 <= k then writeln('no solution')
 else for i:=1 to n do writeln('0 ', i);

 close(input); close(output);
end.
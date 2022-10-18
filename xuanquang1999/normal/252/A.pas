uses math;
const fi = '';
      fo = '';
var n, ans, l, r, i, cur: longint;
    a: array [1..100] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(a[i]);

 ans:=0;
 for l:=1 to n do
  for r:=l to n do
   begin
    cur:=0;
    for i:=l to r do cur:=cur xor a[i];
    ans:=max(ans, cur);
   end;

 writeln(ans);

 close(input); close(output);
end.
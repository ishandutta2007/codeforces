uses math;
const fi = '';
      fo = '';
      maxN = 100;
var i, j, n, cnt, ans: longint;
    a: array [1..maxN] of string;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do readln(a[i]);

 for i:=1 to n do
  begin
   cnt:=0;
   for j:=1 to n do
    if a[i] = a[j] then inc(cnt);
   ans:=max(ans, cnt);
  end;

 writeln(ans);

 close(input); close(output);
end.
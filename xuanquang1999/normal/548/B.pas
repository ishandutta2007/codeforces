uses math;
const fi = '';
      fo = '';
      maxN = 500;
var n, m, q, i, j, x, y, ans: longint;
    a: array [1..maxN, 1..maxN] of longint;
    cnt: array [1..maxN] of longint;

function score(i: longint): longint;
var j, ans, cur: longint;
begin
 ans:=0; cur:=0;
 for j:=1 to m do
  begin
   if a[i, j] = 1 then inc(cur)
   else cur:=0;
   ans:=max(ans, cur);
  end;
 exit(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, m, q);
 for i:=1 to n do
  for j:=1 to m do read(a[i, j]);
 for i:=1 to n do cnt[i]:=score(i);

 for j:=1 to q do
  begin
   readln(x, y);
   a[x, y]:=1-a[x, y];
   cnt[x]:=score(x);

   ans:=0;
   for i:=1 to n do ans:=max(ans, cnt[i]);
   writeln(ans);
  end;

 close(input); close(output);
end.
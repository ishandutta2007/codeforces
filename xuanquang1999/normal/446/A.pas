uses math;
const fi = '';
      fo = '';
      maxN = 100000;
var i, j, n, ans, inv: longint;
    a, l, r: array [1..maxN] of longint;

procedure stop;
begin
 close(input); close(output);
 halt;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(a[i]);

 if n <= 2 then
  begin
   writeln(n);
   stop;
  end;

 l[1]:=1;
 for i:=2 to n do
  if a[i] > a[i-1] then l[i]:=l[i-1]+1
  else l[i]:=1;
 r[n]:=1;
 for i:=n-1 downto 1 do
  if a[i] < a[i+1] then r[i]:=r[i+1]+1
  else r[i]:=1;

 ans:=max(r[2], l[n-1])+1;
 for i:=2 to n-1 do
  if a[i-1]+1 < a[i+1] then ans:=max(ans, l[i-1]+r[i+1]+1)
  else ans:=max(ans, max(l[i-1], r[i+1])+1);

 writeln(ans);

 close(input); close(output);
end.
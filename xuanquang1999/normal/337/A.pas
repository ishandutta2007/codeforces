uses math;
const fi = '';
      fo = '';
var i, j, n, m, tmp, ans: longint;
    a: array [1..50] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, m);
 for i:=1 to m do read(a[i]);

 for i:=1 to m-1 do
  for j:=i+1 to m do
   if a[i] > a[j] then
    begin
     tmp:=a[i];
     a[i]:=a[j];
     a[j]:=tmp;
    end;

 ans:=1000;
 for i:=n to m do ans:=min(ans, a[i]-a[i-n+1]);
 writeln(ans);

 close(input); close(output);
end.
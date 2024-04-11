const fi = '';
      fo = '';
var n, i, j: longint;
    a: array [1..10, 1..10] of longint;
begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do
  begin
   a[i, 1]:=1;
   a[1, i]:=1;
  end;
 for i:=2 to n do
  for j:=2 to n do
   a[i, j]:=a[i-1, j]+a[i, j-1];
 writeln(a[n, n]);

 close(input); close(output);
end.
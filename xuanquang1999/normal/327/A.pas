const fi = '';
      fo = '';
      maxN = 100;
var i, j, k, n, max, count: longint;
    a, b: array [1..maxN] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(a[i]);

 max:=0;
 for i:=1 to n do
  for j:=i to n do
   begin
    count:=0;
    for k:=i to j do a[k]:=1-a[k];
    for k:=1 to n do count:=count+a[k];
    for k:=i to j do a[k]:=1-a[k];
    if count > max then max:=count;
   end;

 writeln(max);

 close(input); close(output);
end.
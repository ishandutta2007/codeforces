const fi = '';
      fo = '';
      maxN = 200000;
var i, j, n, k, x, m: longint;
    a: array [1..maxN] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, k);
 for i:=1 to k do
  begin
   read(m);
   for j:=1 to m do read(a[j]);

   if a[1] = 1 then
    for j:=1 to m do
     if (j = m) or (a[j+1]-a[j] <> 1) then
      begin
       x:=j;
       break;
      end;
  end;

 writeln((n-k-x+1)+(n-x));

 close(input); close(output);
end.
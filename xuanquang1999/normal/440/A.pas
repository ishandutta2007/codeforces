const fi = 'input.txt';
      fo = 'output.txt';
var a: array [1..100000] of longint;
    i, x, n: longint;

begin
 readln(n);
 for i:=1 to n-1 do
  begin
   read(x);
   inc(a[x]);
  end;

 for i:=1 to n do
  if a[i] = 0 then
   begin
    writeln(i);
    break;
   end;

 close(input); close(output);
end.
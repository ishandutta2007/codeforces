const fi = '';
      fo = '';
var a, b, c, n, count: longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 count:=0;
 for b:=1 to n do
  for a:=1 to b do
   begin
    c:=sqr(a)+sqr(b);
    if trunc(sqrt(c)) > n then break
    else if sqr(trunc(sqrt(c))) = c then inc(count)
   end;
 writeln(count);

 close(input); close(output);
end.
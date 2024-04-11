const fi = '';
      fo = '';
var a, b, sum: int64;

function Count(a, b: int64): int64;
var res: int64;
begin
 if b = 0 then exit(0);
 if a >= b then
  begin
   res:=a div b;
   a:=a mod b;
  end
 else res:=0;
 exit(res+Count(b, a));
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(a, b);
 writeln(Count(a, b));

 close(input); close(output);
end.
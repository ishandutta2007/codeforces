const fi = '';
      fo = '';
var n, i, x1, y1, x2, y2, sum: longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do
  begin
   readln(x1, y1, x2, y2);
   sum:=sum+(x2-x1+1)*(y2-y1+1);
  end;
 writeln(sum);

 close(input); close(output);
end.
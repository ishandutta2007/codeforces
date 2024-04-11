const fi = '';
      fo = '';
var n, k, l, r, i, cnt: longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, k);
 for i:=1 to n do
  begin
   readln(l, r);
   cnt:=cnt+r-l+1;
  end;

 writeln(((cnt-1) div k + 1)*k-cnt);

 close(input); close(output);
end.
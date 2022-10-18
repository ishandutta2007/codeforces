uses math;
var n, i: int64;
    s: string;
begin
 readln(n);
 i:=n+1;
 while true do
  begin
   str(i, s);
   if pos('8', s) > 0 then break;
   inc(i);
  end;
 writeln(i-n);
end.
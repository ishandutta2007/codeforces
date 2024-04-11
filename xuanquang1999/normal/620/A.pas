uses math;
var a, b, c, d: longint;

begin
 readln(a, b);
 readln(c, d);
 writeln(max(abs(a-c), abs(b-d)));
end.
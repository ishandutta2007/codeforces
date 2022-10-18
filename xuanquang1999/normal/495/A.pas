const num: array [0..9] of longint = (2, 7, 2, 3, 3, 4, 2, 5, 1, 2);
var n: longint;

begin
 readln(n);
 writeln(num[n div 10]*num[n mod 10]);
end.
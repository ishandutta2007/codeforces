const fi = 'input.txt';
      fo = 'output.txt';
      maxP = 1299709;
      maxN = 100000;
var i, j, n, count: longint;
    isP: array [1..maxP] of boolean;
    p: array [1..maxN] of longint;

begin
 readln(n);

 fillchar(isP, sizeof(isP), true);
 isP[1]:=false;
 for i:=2 to trunc(sqrt(maxP)) do
  if isP[i] then
   begin
    j:=sqr(i);
    while j <= maxP do
     begin
      isP[j]:=false;
      j:=j+i;
     end;
   end;

 count:=0;
 for i:=2 to maxP do
  if isP[i] then
   begin
    write(i, ' ');
    inc(count); if count = n then break;
   end;
 writeln;

 close(input); close(output);
end.
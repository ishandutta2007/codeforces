const fi = '';
      fo = '';
      maxN = 100;
var a: array [1..maxN*2-1] of longint;
    n: longint;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to 2*n-1 do read(a[i]);
end;

procedure Work;
var i, count, max, sum: longint;
begin
 for i:=1 to 2*n-1 do
  if a[i] < 0 then inc(count);
 if (n mod 2 = 0) and (count mod 2 = 1) then
  begin
   max:=1001;
   for i:=1 to 2*n-1 do
    if abs(a[i]) < max then max:=abs(a[i]);
  end
 else max:=0;

 sum:=0;
 for i:=1 to 2*n-1 do sum:=sum+abs(a[i]);
 writeln(sum-2*max);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
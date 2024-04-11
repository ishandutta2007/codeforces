uses math;
const fi = '';
      fo = '';
      maxN = 100000;
var n, i, ans, sum: longint;
    a: array [1..maxN] of longint;
    b: array [1..maxN] of char;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=n downto 1 do read(a[i]);
 readln;
 for i:=n downto 1 do read(b[i]);

 sum:=0;
 for i:=1 to n do
  if b[i] = '1' then sum:=sum+a[i];
 ans:=sum;

 for i:=n downto 1 do
  begin
   if b[i] = '1' then
    begin
     sum:=sum-a[i];
     ans:=max(ans, sum);
    end;
   sum:=sum+a[i];
  end;

 writeln(ans);

 close(input); close(output);
end.
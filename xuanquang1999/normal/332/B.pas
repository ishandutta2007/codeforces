uses math;
const fi = '';
      fo = '';
      maxN = 200000+5;
var n, k, i, l1, r1, l2, r2: longint;
    ans, p1: int64;
    a: array [1..maxN] of int64;
    d: array [0..maxN] of int64;
    max2, p2: array [1..maxN] of int64;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, k);
 for i:=1 to n do read(a[i]);

 d[0]:=0;
 for i:=1 to n do d[i]:=d[i-1]+a[i];

 for l1:=n-2*k+1 downto 1 do
  begin
   l2:=l1+k;
   r2:=l1+2*k-1;
   if d[r2]-d[l2-1] >= max2[l1+1] then
    begin
     p2[l1]:=l2;
     max2[l1]:=d[r2]-d[l2-1];
    end
   else
    begin
     p2[l1]:=p2[l1+1];
     max2[l1]:=max2[l1+1];
    end;
  end;

 for l1:=n-2*k+1 downto 1 do
  begin
   r1:=l1+k-1;
   l2:=l1+k;
   r2:=l1+2*k-1;
   if max2[l1] + d[r1]-d[l1-1] >= ans then
    begin
     p1:=l1;
     ans:=max2[l1] + d[r1]-d[l1-1];
    end;
  end;

 writeln(p1, ' ', p2[p1]);

 close(input); close(output);
end.
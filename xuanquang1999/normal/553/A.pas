const fi = '';
      fo = '';
      maxN = 1005;
      e = round(1e9)+7;
var i, j, n: longint;
    a: array [1..maxN] of int64;
    c: array [0..maxN, 0..maxN] of int64;
    sum, ans: int64;


procedure EndProg;
begin
 close(input); close(output);
 halt;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 c[0, 0]:=1;
 for i:=1 to maxN do
  begin
   c[i, 0]:=1;
   for j:=1 to maxN do c[i, j]:=(c[i-1, j-1]+c[i-1, j]) mod e;
  end;

 readln(n);
 for i:=1 to n do readln(a[i]);

 sum:=a[1]; ans:=1;
 for i:=2 to n do
  begin
   sum:=sum+a[i];
   ans:=(ans*C[sum-1, a[i]-1]) mod e;
  end;

 writeln(ans);

 close(input); close(output);
end.
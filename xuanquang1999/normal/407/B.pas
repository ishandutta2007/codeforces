const fi = '';
      fo = '';
      maxN = 1000;
      e = 1000000007;
var i, j, n, ans: longint;
    a, f: array [1..maxN] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(a[i]);

 f[1]:=2;
 for i:=2 to n do
  begin
   for j:=a[i] to i-1 do f[i]:=(f[i]+f[j]) mod e;
   f[i]:=f[i]+2;
  end;

 ans:=0;
 for i:=1 to n do ans:=(ans+f[i]) mod e;
 writeln(ans);

 close(input); close(output);
end.
uses math;
const fi = '';
      fo = '';
      e = 1000000009;
var n, m, k, mulcnt, a, b: int64;

function pow(a, b: int64): int64;
var p: int64;
begin
 if b = 0 then exit(1)
 else
  begin
   p:=pow(a, b div 2) mod e;
   if (b mod 2 = 0) then exit(sqr(p) mod e)
   else exit((sqr(p) mod e * a) mod e);
  end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, m, k);

 mulcnt:=max(0, n div k - (n-m));
 //writeln(pow(2, mulcnt)*k+m-k*mulcnt);
 a:=(pow(2, mulcnt+1)+e-1) * k - k;
 b:=m-k*mulcnt;
 writeln((a + b + 1000*e) mod e);

 close(input); close(output);
end.
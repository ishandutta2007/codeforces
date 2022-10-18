const fi = '';
      fo = '';
var i, n, k: longint;
    a: array [1..1000] of longint;
    ok: boolean;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(a[i]);

 k:=(n-a[1]) mod n;
 for i:=1 to n do
  if i mod 2 = 0 then a[i]:=(a[i]-k+n) mod n
  else a[i]:=(a[i]+k) mod n;

 ok:=true;
 for i:=1 to n do
  if a[i] <> i-1 then
   begin
    ok:=false;
    break;
   end;

 if ok then writeln('Yes')
 else writeln('No');

 close(input); close(output);
end.
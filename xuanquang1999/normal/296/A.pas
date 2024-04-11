const fi = '';
      fo = '';
var i, n: longint;
    a: array [1..100] of longint;
    cnt: array [1..1000] of longint;
    ok: boolean;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do
  begin
   read(a[i]);
   inc(cnt[a[i]]);
  end;

 ok:=true;
 for i:=1 to 1000 do
  if cnt[i] > (n-1) div 2 + 1 then ok:=false;

 if ok then writeln('YES')
 else writeln('NO');

 close(input); close(output);
end.
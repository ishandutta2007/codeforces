const fi = '';
      fo = '';
      maxN = 100000;
var i, n, m, k, t, p, x: longint;
    a: array [1..maxN] of int64;
    f: array [0..maxN] of int64;
    last: array [0..maxN] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, m);
 for i:=1 to n do read(a[i]);

 for i:=1 to m do
  begin
   read(t);
   if t = 1 then
    begin
     read(p, x);
     a[p]:=x;
     last[p]:=k;
    end
   else if t = 2 then
    begin
     read(x);
     inc(k);
     f[k]:=f[k-1]+x;
    end
   else if t = 3 then
    begin
     read(p);
     writeln(a[p]+f[k]-f[last[p]]);
    end;
  end;

 close(input); close(output);
end.
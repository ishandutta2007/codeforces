const fi = '';
      fo = '';
      maxN = 100;
var n, m, i, x, y: longint;
    a: array [0..maxN+1] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(a[i]);
 readln(m);
 for i:=1 to m do
  begin
   readln(x, y);
   a[x-1]:=a[x-1]+y-1;
   a[x+1]:=a[x+1]+a[x]-y;
   a[x]:=0
  end;

 for i:=1 to n do writeln(a[i]);

 close(input); close(output);
end.
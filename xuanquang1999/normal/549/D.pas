const fi = '';
      fo = '';
var i, j, x, y, n, m, ans, tmp: longint;
    a: array [1..100, 1..100] of char;
    b: array [1..100, 1..100] of longint;
    cof: array ['A'..'Z'] of longint;
    va: array ['A'..'Z'] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 cof['W']:=2;
 cof['B']:=-2;
 va['W']:=1;
 va['B']:=-1;

 readln(n, m);
 for i:=1 to n do
  begin
   for j:=1 to m do read(a[i, j]);
   readln;
  end;

 for i:=1 to n do
  for j:=1 to m do b[i, j]:=va[a[n, m]];
 ans:=1;

 for i:=n downto 1 do
  begin
   for j:=m downto 1 do
    begin
     while b[i, j] <> va[a[i, j]] do
      begin
       inc(ans);
       for x:=1 to i do
        for y:=1 to j do b[x, y]:=b[x, y]-b[i, j]+va[a[i, j]];
      end;
    end;
  end;

 writeln(ans);

 close(input); close(output);
end.
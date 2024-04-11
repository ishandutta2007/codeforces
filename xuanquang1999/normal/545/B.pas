const fi = '';
      fo = '';
      maxN = 100000;
var a, b: array [1..maxN] of char;
    i, n, cnt, k: longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 n:=0;
 while not eoln do
  begin
   inc(n);
   read(a[n]);
  end;
 readln;
 readln(b);

 cnt:=0;
 for i:=1 to n do
  if a[i] = b[i] then inc(cnt);
 if (n-cnt) mod 2 = 1 then writeln('impossible')
 else
  begin
   k:=0;
   for i:=1 to n do
    if a[i] = b[i] then write(a[i])
    else if k < (n-cnt) div 2 then
     begin
      write(a[i]);
      inc(k);
     end
    else write(b[i]);
  end;


 close(input); close(output);
end.
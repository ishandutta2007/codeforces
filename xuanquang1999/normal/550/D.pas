const fi = '';
      fo = '';
      maxN = 10000;
var k, i, j, posJ, min, m, n: longint;
    u, v: array [1..maxN] of longint;
    cnt: array [1..maxN] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(k);
 if k mod 2 = 0 then writeln('NO')
 else if k = 1 then
  begin
   writeln('YES');
   writeln('2 1');
   writeln('1 2');
  end
 else
  begin
   n:=k+2;
   for i:=1 to n-1 do cnt[i]:=2;
   cnt[n]:=1;
   for i:=1 to n do
    while cnt[i] < k do
     begin
      posJ:=0; min:=n;
      for j:=i+2 to n do
       if (j <> i) and (cnt[j] < min) and (cnt[j] < k) then
        begin
         min:=cnt[j];
         posJ:=j;
        end;

      inc(cnt[i]); inc(cnt[posJ]);
      inc(m);
      u[m]:=i; v[m]:=posJ;
     end;
   writeln('YES');
   writeln(2*n, ' ', m*2+2*(n-1)+1);
   for i:=1 to n-1 do writeln(i, ' ', i+1);
   for i:=n+1 to 2*n-1 do writeln(i, ' ', i+1);
   for i:=1 to m do writeln(u[i], ' ', v[i]);
   writeln(1, ' ', n*2);
   for i:=1 to m do writeln(n*2+1-u[i], ' ', n*2+1-v[i]);
  end;

 close(input); close(output);
end.
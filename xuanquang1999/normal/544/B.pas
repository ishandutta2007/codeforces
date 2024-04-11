const fi = '';
      fo = '';
var i, j, n, k, cnt: longint;
    a: array [1..100, 1..100] of char;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, k);
 for i:=1 to n do
  for j:=1 to n do
   if (i+j) mod 2 = 0 then a[i, j]:='L'
   else a[i, j]:='S';

 if (n*n+1) div 2 < k then writeln('NO')
 else
  begin
   writeln('YES');
   for i:=1 to n do
    begin
     for j:=1 to n do
      if cnt < k then
       begin
        write(a[i, j]);
        if a[i, j] = 'L' then inc(cnt);
       end
      else write('S');
     writeln;
    end;
  end;
 close(input); close(output);
end.
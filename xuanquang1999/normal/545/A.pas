const fi = '';
      fo = '';
var n, i, j, x, ans: longint;
    cnt: array [1..100] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do
  for j:=1 to n do
   begin
    read(x);
    if x = 1 then inc(cnt[i])
    else if x = 2 then inc(cnt[j])
    else if x = 3 then
     begin
      inc(cnt[i]);
      inc(cnt[j]);
     end;
   end;

 ans:=0;
 for i:=1 to n do
  if cnt[i] = 0 then inc(ans);
 writeln(ans);
 for i:=1 to n do
  if cnt[i] = 0 then write(i, ' ');

 close(input); close(output);
end.
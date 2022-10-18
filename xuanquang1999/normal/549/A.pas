const fi = '';
      fo = '';
      dx: array [1..4] of longint = (0, 1, 0, 1);
      dy: array [1..4] of longint = (0, 0, 1, 1);

var i, j, k, n, m, ans: longint;
    cnt: array [1..4] of longint;
    a: array [1..50, 1..50] of char;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, m);
 for i:=1 to n do
  begin
   for j:=1 to m do read(a[i, j]);
   readln;
  end;

 for i:=1 to n-1 do
  for j:=1 to m-1 do
   begin
    fillchar(cnt, sizeof(cnt), 0);
    for k:=1 to 4 do
     case a[i+dx[k], j+dy[k]] of
      'f': inc(cnt[1]);
      'a': inc(cnt[2]);
      'c': inc(cnt[3]);
      'e': inc(cnt[4]);
     end;
    inc(ans);
    for k:=1 to 4 do
     if cnt[k] = 0 then
      begin
       dec(ans);
       break;
      end;
   end;

 writeln(ans);

 close(input); close(output);
end.
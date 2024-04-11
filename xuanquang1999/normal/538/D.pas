const fi = '';
      fo = '';
      maxN = 55;
var a: array [1..maxN, 1..maxN] of char;
    ans: array [1-maxN..maxN-1, 1-maxN..maxN-1] of char;
    marked: array [1..maxN, 1..maxN] of boolean;
    px, py: array [1..sqr(maxN)] of longint;
    n, k: longint;

procedure Enter;
var i, j: longint;
begin
 readln(n);
 for i:=1 to n do
  begin
   for j:=1 to n do
    begin
     read(a[i, j]);
     if a[i, j] = 'o' then
      begin
       inc(k);
       px[k]:=i; py[k]:=j;
      end;
    end;
   readln;
  end;

 fillchar(ans, sizeof(ans), '.');
end;

procedure Work;
var dx, dy, x, y, i: longint;
    ok: boolean;
begin
 for dx:=1-n to n-1 do
  for dy:=1-n to n-1 do
   begin
    ok:=true;
    for i:=1 to k do
     begin
      x:=px[i]+dx; y:=py[i]+dy;
      if (x > 0) and (x <= n) and (y > 0) and (y <= n) and (a[x, y] = '.') then
       begin
        ok:=false;
        break;
       end;
     end;
    if not ok then continue;

    for i:=1 to k do
     begin
      x:=px[i]+dx; y:=py[i]+dy;
      if (x > 0) and (x <= n) and (y > 0) and (y <= n) then marked[x, y]:=true;
     end;
    ans[dx, dy]:='x';
   end;
end;

procedure Answer;
var i, j: longint;
begin
 for i:=1 to n do
  for j:=1 to n do
   if (a[i, j] = 'x') and not marked[i, j] then
    begin
     writeln('NO');
     exit;
    end;

 writeln('YES');
 ans[0, 0]:='o';
 for i:=1-n to n-1 do
  begin
   for j:=1-n to n-1 do write(ans[i, j]);
   writeln;
  end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.
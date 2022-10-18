const fi = '';
      fo = '';
      maxN = 100000;
var n, sx, sy, ex, ey: longint;
    s: array [1..maxN] of char;
    d1, d2: char;

procedure Enter;
var i: longint;
begin
 readln(n, sx, sy, ex, ey);
 for i:=1 to n do read(s[i]);
end;

procedure Work;
var i, x, y: longint;
begin
 x:=sx; y:=sy;
 for i:=1 to n+1 do
  begin
   if (x >= ex) and (s[i] = 'E') then continue;
   if (x <= ex) and (s[i] = 'W') then continue;
   if (y >= ey) and (s[i] = 'N') then continue;
   if (y <= ey) and (s[i] = 'S') then continue;
   case s[i] of
    'E': inc(x);
    'W': dec(x);
    'N': inc(y);
    'S': dec(y);
   end;
   if (x = ex) and (y = ey) then
    begin
     writeln(i);
     exit;
    end;
  end;
 writeln(-1);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
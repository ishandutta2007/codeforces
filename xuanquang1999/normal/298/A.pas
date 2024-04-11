const fi = '';
      fo = '';
      maxN = 1000;
var s: array [1..maxN] of char;
    n: longint;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do read(s[i]);
end;

procedure Work;
var l, r, i: longint;
begin
 if (pos('L', s) = 0) and (pos('R', s) = 0) then
  begin
   writeln('1 1');
   exit;
  end;
 if pos('R', s) = 0 then
  begin
   for i:=1 to n do
    if s[i] = 'L' then l:=i;
   writeln(l, ' ', pos('L', s)-1);
   exit;
  end;
 if pos('L', s) = 0 then
  begin
   for i:=1 to n do
    if s[i] = 'R' then r:=i;
   writeln(pos('R', s), ' ', r+1);
   exit;
  end;
 for l:=1 to n do
  if s[l] = 'R' then break;
 for r:=1 to n do
  if s[r] = 'L' then break;
 writeln(l, ' ', r-1);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
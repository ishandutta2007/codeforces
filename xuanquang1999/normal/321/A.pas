const fi = '';
      fo = '';
      maxN = 100;
var s: array [1..maxN] of char;
    dx, dy: array ['A'..'Z'] of longint;
    px, py: array [0..maxN] of longint;
    a, b, n, mx, my: longint;

procedure Enter;
begin
 readln(a, b);
 while not eoln do
  begin
   inc(n);
   read(s[n]);
  end;
end;

function Check(x, y: longint): boolean;
begin
 if y = 0 then exit(x = 0);
 if ((x > 0) and (y < 0)) or ((x < 0) and (y > 0)) then exit(false);
 exit(x mod y = 0);
end;

procedure Work;
var i: longint;
begin
 dy['U']:=1; dy['D']:=-1;
 dx['L']:=-1; dx['R']:=1;
 for i:=1 to n do
  begin
   px[i]:=px[i-1]+dx[s[i]];
   py[i]:=py[i-1]+dy[s[i]];
  end;

 for i:=0 to n-1 do
  if Check(a-px[i], px[n]) and Check(b-py[i], py[n])
  and ((px[n] = 0) or (py[n] = 0) or ((a-px[i]) div px[n] = (b-py[i]) div py[n])) then
   begin
    writeln('Yes');
    exit;
   end;
 writeln('No');
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
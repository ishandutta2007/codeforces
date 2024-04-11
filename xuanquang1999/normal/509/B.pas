uses math;
const fi = '';
      fo = '';
      maxN = 100+5;
var n, c: longint;
    a: array [1..maxN] of longint;
    f: array [1..maxN, 0..maxN] of longint;

procedure Enter;
var i: longint;
begin
 readln(n, c);
 for i:=1 to n do read(a[i]);
end;

procedure Work;
var k, i, j, minC: longint;
begin
 for i:=1 to n do f[i, 0]:=0;
 for k:=1 to c do
  begin
   minC:=100;
   for i:=1 to n do
    minC:=min(minC, a[i]-f[i, 0]);
   for i:=1 to n do
    begin
     for j:=f[i, 0]+1 to min(a[i], f[i, 0]+minC+1) do f[i, j]:=k;
     f[i, 0]:=min(a[i], f[i, 0]+minC+1);
    end;
  end;
 for i:=1 to n do
  if f[i, 0] < a[i] then
   begin
    writeln('NO');
    exit;
   end;
 writeln('YES');
 for i:=1 to n do
  begin
   for j:=1 to a[i] do write(f[i, j], ' ');
   writeln;
  end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
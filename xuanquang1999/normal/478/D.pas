uses math;
const fi = '';
      fo = '';
      e = round(1e9)+7;
      maxN = 200000;
var ih, ir, h, r, g, sum: longint;
    f1, f2: array [0..maxN] of longint;

function trinum(x: longint): longint;
begin
 exit((x*(x+1)) div 2);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(r, g);
 for h:=1 to r+g do
  if trinum(h) > r+g then break;
 dec(h);

 f1[0]:=1;
 for ih:=1 to h do
  begin
   for ir:=ih to min(r, trinum(ih)) do
    f2[ir]:=(f2[ir]+f1[ir-ih]) mod e;
   for ir:=max(0, trinum(ih)-g) to min(r, trinum(ih-1)) do
    f2[ir]:=(f2[ir]+f1[ir]) mod e;
   f1:=f2;
   fillchar(f2, sizeof(f2), 0);
  end;

 for ir:=0 to r do sum:=(sum+f1[ir]) mod e;

 writeln(sum);

 close(input); close(output);
end.
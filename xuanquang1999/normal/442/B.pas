uses math;
const fi = '';
      fo = '';
      maxN = 100;
var i, j, n: longint;
    p: array [1..maxN] of extended;
    tmp, ans, prod: extended;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(p[i]);

 for i:=1 to n-1 do
  for j:=i+1 to n do
   if p[i] > p[j] then
    begin
     tmp:=p[i];
     p[i]:=p[j];
     p[j]:=tmp;
    end;

 ans:=0; prod:=1;
 for i:=n downto 1 do
  begin
   tmp:=ans*(1-p[i])+p[i]*prod;
   if tmp < ans then break;
   ans:=tmp;
   prod:=prod*(1-p[i]);
  end;

 writeln(ans:0:10);

 close(input); close(output);
end.
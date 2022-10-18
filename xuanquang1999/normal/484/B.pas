uses math;
const fi = '';
      fo = '';
      maxN = 200000;
      maxX = 2000000;
var n, ans: longint;
    a: array [1..maxN] of longint;
    l: array [1..maxX] of longint;
    avail: array [1..maxX] of boolean;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do
  begin
   read(a[i]);
   avail[a[i]]:=true;
  end;
 for i:=1 to maxX-1 do
  if avail[i] then l[i+1]:=i
  else l[i+1]:=l[i];
end;

procedure Work;
var j, x: longint;
begin
 ans:=0;
 for j:=1 to maxX div 2 do
  if avail[j] then
   begin
    x:=2*j;
    while x <= maxX do
     begin
      if l[x] > j then ans:=max(ans, l[x] mod j);
      x:=x+j;
     end;
   end;
end;

procedure Answer;
begin
 writeln(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.
uses math;
const fi = '';
      fo = '';
      maxN = 300;
var i, j, k, a, b, c: longint;
    n, ans, cnt1, cnt2, max1, max2: longint;
    x, y: array [1..maxN] of longint;
    p1, p2: array [1..maxN] of longint;

function Area(x1, y1, x2, y2, x3, y3: longint): longint;
var a1, a2, b1, b2: longint;
begin
 a1:=x1-x2;
 a2:=x1-x3;
 b1:=y1-y2;
 b2:=y1-y3;
 exit(abs(a1*b2-a2*b1));
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do readln(x[i], y[i]);

 for i:=1 to n-1 do
  for j:=i+1 to n do
   begin
    a:=y[j]-y[i];
    b:=x[i]-x[j];
    c:=-(a*x[i]+b*y[i]);

    cnt1:=0; cnt2:=0;
    for k:=1 to n do
     if a*x[k]+b*y[k]+c < 0 then
      begin
       inc(cnt1);
       p1[cnt1]:=k;
      end
     else if a*x[k]+b*y[k]+c > 0 then
      begin
       inc(cnt2);
       p2[cnt2]:=k;
      end;

    if (cnt1 = 0) or (cnt2 = 0) then continue;

    max1:=0; max2:=0;
    for k:=1 to cnt1 do
     max1:=max(max1, Area(x[i], y[i], x[j], y[j], x[p1[k]], y[p1[k]]));
    for k:=1 to cnt2 do
     max2:=max(max2, Area(x[i], y[i], x[j], y[j], x[p2[k]], y[p2[k]]));
    ans:=max(ans, max1+max2);
   end;

 writeln((ans/2):0:10);

 close(input); close(output);
end.
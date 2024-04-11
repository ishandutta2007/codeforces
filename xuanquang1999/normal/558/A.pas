uses math;
const fi = '';
      fo = '';

var n, i, j, x, y, cnt1, cnt2, k: longint;
    x1, a1, x2, a2, d1, d2: array [0..100] of longint;

procedure SwapI(var a, b: longint);
var t: longint;
begin
 t:=a; a:=b; b:=t;
end;

procedure EndProg;
begin
 close(input); close(output);
 halt;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do
  begin
   read(x, y);
   if x < 0 then
    begin
     inc(cnt1);
     x1[cnt1]:=x;
     a1[cnt1]:=y;
    end
   else
    begin
     inc(cnt2);
     x2[cnt2]:=x;
     a2[cnt2]:=y;
    end;
  end;

 for i:=1 to cnt1-1 do
  for j:=i+1 to cnt1 do
   if x1[i] < x1[j] then
    begin
     SwapI(x1[i], x1[j]);
     SwapI(a1[i], a1[j]);
    end;

 for i:=1 to cnt2-1 do
  for j:=i+1 to cnt2 do
   if x2[i] > x2[j] then
    begin
     SwapI(x2[i], x2[j]);
     SwapI(a2[i], a2[j]);
    end;

 for i:=1 to cnt1 do d1[i]:=d1[i-1]+a1[i];
 for i:=1 to cnt2 do d2[i]:=d2[i-1]+a2[i];

 k:=min(cnt1, cnt2);
 writeln(max(d1[k]+d2[min(k+1, cnt2)], d2[k]+d1[min(k+1, cnt1)]));

 close(input); close(output);
end.
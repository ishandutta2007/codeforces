uses math;
const fi = '';
      fo = '';
      maxC = round(1e9)+7;
var nTest, iTest, i, j, k, l, minR: longint;
    x, y, a, b, x1, y1: array [1..4] of longint;

procedure Rotate(x, y, a, b, t: longint; var x1, y1: longint);
var i: longint;
begin
 x1:=x; y1:=y;
 for i:=1 to t do
  begin
   x1:=a-(y-b); y1:=b+(x-a);
   x:=x1; y:=y1;
  end;
end;

function SqrEL(x1, y1, x2, y2: longint): Dword;
begin
 exit(sqr(x1-x2)+sqr(y1-y2));
end;

function Check: boolean;
var i, j, cnt, tmp: Dword;
    a: array [1..6] of Dword;
begin
 cnt:=0;
 for i:=1 to 3 do
  for j:=i+1 to 4 do
   begin
    inc(cnt);
    a[cnt]:=SqrEL(x1[i], y1[i], x1[j], y1[j]);
   end;

 for i:=1 to cnt-1 do
  for j:=i+1 to cnt do
   if a[i] > a[j] then
    begin
     tmp:=a[i];
     a[i]:=a[j];
     a[j]:=tmp;
    end;

 if (a[1] = 0) or (a[1] <> a[2]) or (a[2] <> a[3]) or (a[3] <> a[4]) or (a[5] <> a[6]) or (a[4] = a[5]) then exit(false);
 exit(true);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(nTest);
 for iTest:=1 to nTest do
  begin
   for i:=1 to 4 do readln(x[i], y[i], a[i], b[i]);

   minR:=maxC;
   for i:=0 to 3 do
    for j:=0 to 3 do
     for k:=0 to 3 do
      for l:=0 to 3 do
       if i+j+k+l < minR then
        begin
         Rotate(x[1], y[1], a[1], b[1], i, x1[1], y1[1]);
         Rotate(x[2], y[2], a[2], b[2], j, x1[2], y1[2]);
         Rotate(x[3], y[3], a[3], b[3], k, x1[3], y1[3]);
         Rotate(x[4], y[4], a[4], b[4], l, x1[4], y1[4]);

         if Check then minR:=i+j+k+l;
        end;

   if minR = maxC then writeln(-1)
   else writeln(minR);
  end;

 close(input); close(output);
end.
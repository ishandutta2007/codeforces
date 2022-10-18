uses math;
const fi = '';
      fo = '';
      maxN = 100000*2;
var n, n1, n2, count: longint;
    a: array [1..maxN] of longint;
    p1, p2, c1, c2: array [0..maxN] of longint;
    resS, resT: array [1..maxN] of longint;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
 fillDword(c1, sizeof(c1) div 4, maxN);
 fillDword(c2, sizeof(c2) div 4, maxN);
 fillDword(p1, sizeof(p1) div 4, maxN);
 fillDword(p2, sizeof(p2) div 4, maxN);
 c1[0]:=0; c2[0]:=0;
 for i:=1 to n do
  begin
   c1[i]:=c1[i-1]; c2[i]:=c2[i-1];
   if a[i] = 1 then inc(c1[i]) else inc(c2[i]);
  end;
 n1:=0; n2:=0;
 p1[0]:=0; p2[0]:=0;
 for i:=1 to n do
  if a[i] = 1 then
   begin inc(n1); p1[n1]:=i; end
  else
   begin inc(n2); p2[n2]:=i; end
end;

procedure Work;
var t, s1, s2, i1, i2: longint;
begin
 count:=0;
 for t:=n downto 1 do
  begin
   s1:=0; s2:=0;
   i1:=0; i2:=0;
   while true do
    if p1[i1+t] < p2[i2+t] then
     begin
      i1:=i1+t; i2:=c2[p1[i1]];
      inc(s1);
     end
    else if p1[i1+t] > p2[i2+t] then
     begin
      i2:=i2+t; i1:=c1[p2[i2]];
      inc(s2);
     end
     else break;

   if (((s1 > s2) and (p1[i1] > p2[i2])) or ((s1 < s2) and (p1[i1] < p2[i2])))
   and (i1+i2 = n) then
    begin
     inc(count);
     resS[count]:=max(s1, s2);
     resT[count]:=t;
    end;
  end;
end;

procedure Swap(var a, b: longint);
var t: longint;
begin
 t:=a; a:=b; b:=t;
end;

procedure QSort(l, r: longint);
var i, j, p1, p2: longint;
begin
 if l >= r then exit;
 i:=l; j:=r;
 p1:=resS[(i+j) div 2];
 p2:=resT[(i+j) div 2];
 while i <= j do
  begin
   while (resS[i] < p1) or ((resS[i] = p1) and (resT[i] < p2)) do inc(i);
   while (resS[j] > p1) or ((resS[j] = p1) and (resT[j] > p2)) do dec(j);
   if l <= r then
    begin
     Swap(resS[i], resS[j]);
     Swap(resT[i], resT[j]);
     inc(i); dec(j);
    end;
  end;
 QSort(l, j); QSort(i, r);
end;

procedure Answer;
var i: longint;
begin
 QSort(1, count);
 writeln(count);
 for i:=1 to count do
  writeln(resS[i], ' ', resT[i]);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.
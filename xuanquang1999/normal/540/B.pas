const fi = '';
      fo = '';
      maxN = 5000;
var a: array [-maxN..maxN] of longint;
    n, k, p, x, y: longint;
    l, r: longint;

procedure Enter;
var i: longint;
begin
 readln(n, k, p, x, y);
 for i:=1 to k do read(a[i]);
end;

procedure BubbleSort;
var i, j, tmp: longint;
begin
 for i:=1 to k-1 do
  for j:=i+1 to k do
   if a[i] > a[j] then
    begin
     tmp:=a[i];
     a[i]:=a[j];
     a[j]:=tmp;
    end;
end;

procedure add1;
begin
 dec(l); a[l]:=1;
end;

procedure addy;
begin
 inc(r); a[r]:=y;
end;

procedure Work;
begin
 l:=1; r:=k;
 if k mod 2 = 0 then
  begin
   if a[k div 2] >= y then add1
   else addy;
  end;

 while (r-l)+1 < n do
  begin
   if a[(l+r) div 2-1] >= y then
    begin
     add1; add1;
    end
   else if a[(l+r) div 2] >= y then
    begin
     add1; addy;
    end
   else
    begin
     addy; addy;
    end;
  end;
end;

procedure Answer;
var i, sum: longint;
begin
 sum:=0;
 for i:=l to r do sum:=sum+a[i];
 if (sum > x) or (a[(l+r) div 2] < y) then
  begin
   writeln(-1);
   exit;
  end;

 for i:=l to 0 do write(a[i], ' ');
 for i:=k+1 to r do write(a[i], ' ');
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 BubbleSort;
 Work;
 Answer;

 close(input); close(output);
end.
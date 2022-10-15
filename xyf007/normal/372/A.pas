var
  n,aa,bb,sum:int64;
  i:longint;
  a,b,c:array[1..500001] of int64;
procedure sort(l,r: longint);
var
  i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
    while a[i]<x do
      inc(i);
    while x<a[j] do
      dec(j);
    if not(i>j) then
      begin
        y:=a[i];
        a[i]:=a[j];
        a[j]:=y;
        inc(i);
        dec(j)
      end;
    until i>j;
    if l<j then
      sort(l,j);
    if i<r then
      sort(i,r)
end;
begin
  readln(n);
  for i:=1 to n do
    readln(a[i]);
  sort(1,n);
  for i:=1 to n div 2 do
    b[i]:=a[i];
  for i:=n div 2+1 to n do
    c[i-n div 2]:=a[i];
  aa:=1;
  bb:=1;
  sum:=n;
  while (aa<=n div 2) and (n div 2+bb<=n) do
    if 2*b[aa]<=c[bb] then
      begin
        inc(aa);
        inc(bb);
        dec(sum)
      end
    else
      inc(bb);
  write(sum)
end.
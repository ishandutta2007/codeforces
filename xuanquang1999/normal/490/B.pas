const fi = '';
      fo = '';
      maxN = 200000;
type mang = array [0..maxN] of longint;
var a, b, c: mang;
    n: longint;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do readln(a[i], b[i]);
end;

procedure Swap(var a, b: longint);
var t: longint;
begin
 t:=a; a:=b; b:=t;
end;

procedure QSortC(l, r: longint);
var i, j, p: longint;
begin
 if l >= r then exit;
 i:=l; j:=r;
 p:=c[(i+j) div 2];
 while i <= j do
  begin
   while c[i] < p do inc(i);
   while c[j] > p do dec(j);
   if i <= j then
    begin
     Swap(c[i], c[j]);
     inc(i); dec(j);
    end;
  end;
 QSortC(l, j); QSortC(i, r);
end;

procedure QSortA(l, r: longint);
var i, j, p: longint;
begin
 if l >= r then exit;
 i:=l; j:=r;
 p:=a[(i+j) div 2];
 while i <= j do
  begin
   while a[i] < p do inc(i);
   while a[j] > p do dec(j);
   if i <= j then
    begin
     Swap(a[i], a[j]);
     Swap(b[i], b[j]);
     inc(i); dec(j);
    end;
  end;
 QSortA(l, j); QSortA(i, r);
end;

function findA(x: longint): longint;
var l, r, mid: longint;
begin
 l:=1; r:=n;
 while l <= r do
  begin
   mid:=(l+r) div 2;
   if a[mid] < x then l:=mid+1
   else if a[mid] > x then r:=mid-1
   else exit(mid);
  end;
 exit(-1);
end;

function findC(x: longint): longint;
var l, r, mid: longint;
begin
 l:=1; r:=n;
 while l <= r do
  begin
   mid:=(l+r) div 2;
   if c[mid] < x then l:=mid+1
   else if c[mid] > x then r:=mid-1
   else exit(mid);
  end;
 exit(-1);
end;

procedure Work;
var i: longint;
begin
 c:=b;
 QSortC(1, n);
 for i:=1 to n do
  if findC(a[i]) = -1 then
   begin
    c[1]:=a[i];
    break;
   end;
 QSortA(1, n);

 for i:=2 to n do c[i]:=b[findA(c[i-2])];
end;

procedure Answer;
var i: longint;
begin
 for i:=1 to n do write(c[i], ' ');
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.
const fi = '';
      fo = '';
      maxN = 100000;
type mang = array [1..maxN] of longint;
var n: longint;
    a1, a2, a3: mang;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do read(a1[i]);
 for i:=1 to n-1 do read(a2[i]);
 for i:=1 to n-2 do read(a3[i]);
end;

procedure Swap(var a, b: longint);
var t: longint;
begin
 t:=a; a:=b; b:=t;
end;

procedure QSort(var a: mang; n: longint);
 procedure sort(l, r: longint);
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
      inc(i); dec(j);
     end;
   end;
  sort(l, j); sort(i, r);
 end;
begin
 sort(1, n);
end;

function Different(a1, a2: mang; n1, n2: longint): longint;
var i: longint;
begin
 for i:=1 to n2 do
  if a1[i] <> a2[i] then exit(a1[i]);
 exit(a1[n1]);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;

 QSort(a1, n);
 QSort(a2, n-1);
 QSort(a3, n-2);

 writeln(Different(a1, a2, n, n-1));
 writeln(Different(a2, a3, n-1, n-2));

 close(input); close(output);
end.
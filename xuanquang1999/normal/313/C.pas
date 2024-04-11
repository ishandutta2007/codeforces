const fi = '';
      fo = '';
      maxN = 2*round(1e6);
      maxS = trunc(sqrt(maxN));
var n: longint;
    a: array [1..maxN] of longint;
    d: array [0..maxN] of Qword;
    ans: Qword;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
end;

procedure QSort(l, r: longint);
var i, j, p: longint;
    tmp: longint;
begin
 if l >= r then exit;
 i:=l; j:=r;
 p:=a[(i+j) div 2];
 while i <= j do
  begin
   while a[i] > p do inc(i);
   while a[j] < p do dec(j);
   if i <= j then
    begin
     tmp:=a[i];
     a[i]:=a[j];
     a[j]:=tmp;
     inc(i); dec(j);
    end;
  end;
 QSort(l, j); QSort(i, r);
end;

procedure Work;
var i: longint;
begin
 d[0]:=0;
 for i:=1 to n do d[i]:=d[i-1]+a[i];

 i:=1; ans:=0;
 while i <= n do
  begin
   ans:=ans + d[i];
   i:=i*4;
  end;
 writeln(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 QSort(1, n);
 Work;

 close(input); close(output);
end.
const fi = '';
      fo = '';
      maxN = 300;
var p: array [1..maxN] of longint;
    a: array [1..maxN, 1..maxN] of boolean;
    free: array [1..maxN] of boolean;
    Stack: array [1..maxN] of longint;
    n, Top: longint;

procedure Enter;
var i, j: longint;
    c: char;
begin
 readln(n);
 for i:=1 to n do read(p[i]);
 readln;
 for i:=1 to n do
  begin
   for j:=1 to n do
    begin
     read(c);
     if c = '1' then a[i, j]:=true
     else a[i, j]:=false;
    end;
   readln;
  end;
end;

procedure Visit(u: longint);
var v: longint;
begin
 free[u]:=false;
 inc(Top); Stack[Top]:=u;
 for v:=1 to n do
  if a[u, v] and free[v] then Visit(v);
end;

procedure Swap(var a, b: longint);
var t: longint;
begin
 t:=a; a:=b; b:=t;
end;

procedure SortStack(l, r: longint);
var i, j, tmp: longint;
begin
 for i:=l to r-1 do
  for j:=i+1 to r do
   if Stack[i] > Stack[j] then
   Swap(Stack[i], Stack[j]);
end;

procedure SortP(l, r: longint);
var i, j, tmp: longint;
begin
 for i:=l to r-1 do
  for j:=i+1 to r do
   if p[Stack[i]] > p[Stack[j]] then
   Swap(p[Stack[i]], p[Stack[j]]);
end;

procedure DFS;
var u: longint;
begin
 fillchar(free, sizeof(free), true);
 for u:=1 to n do
  if free[u] then
   begin
    Top:=0;
    Visit(u);
    SortStack(1, Top);
    SortP(1, Top);
   end;
end;

procedure Answer;
var i: longint;
begin
 for i:=1 to n do write(p[i], ' ');
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 DFS;
 Answer;

 close(input); close(output);
end.
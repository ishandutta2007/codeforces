const fi = '';
      fo = '';
      maxN = 100;
type mang = array [0..maxN] of longint;
var n, m, cCount: longint;
    a: array [1..maxN, 1..maxN] of boolean;
    free: array [1..maxN] of boolean;
    cc, t: array [1..maxN] of mang;
    tmp: mang;

procedure Enter;
var i, u, v: longint;
begin
 readln(n, m);
 for i:=1 to m do
  begin
   readln(u, v);
   a[u, v]:=true; a[v, u]:=true;
  end;
end;

procedure Visit(u: longint);
var v: longint;
begin
 inc(cc[cCount, 0]);
 cc[cCount, cc[cCount, 0]]:=u;
 free[u]:=false;
 for v:=1 to n do
  if a[u, v] and free[v] then Visit(v);
end;

procedure Work;
var i, j, u: longint;
begin
 fillchar(free, sizeof(free), true);
 cCount:=0;
 for u:=1 to n do
  if free[u] then
   begin
    inc(cCount);
    Visit(u);
   end;

 for i:=1 to cCount-1 do
  for j:=i+1 to cCount do
   if cc[i, 0] < cc[j, 0] then
    begin
     tmp:=cc[i];
     cc[i]:=cc[j];
     cc[j]:=tmp;
    end;

 fillchar(free, sizeof(free), true);
 for i:=1 to n div 3 do
  for j:=1 to cCount do
   if free[j] and (cc[j, 0]+t[i, 0] <= 3) then
    begin
     free[j]:=false;
     for u:=1 to cc[j, 0] do
      begin
       inc(t[i, 0]);
       t[i, t[i, 0]]:=cc[j, u];
      end;
    end;

 for i:=1 to cCount do
  if free[i] then
   begin
    writeln(-1);
    exit;
   end;

 for i:=1 to n div 3 do
  begin
   for j:=1 to 3 do write(t[i, j], ' ');
   writeln;
  end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
uses math;
const fi = '';
      fo = '';
      maxN = 1005;
var m, n: longint;
    a: array [1..maxN, 1..maxN] of longint;
    dp11, dpm1, dp1n, dpmn: array [0..maxN+1, 0..maxN+1] of longint;

procedure Enter;
var i, j: longint;
begin
 readln(m, n);
 for i:=1 to m do
  for j:=1 to n do read(a[i, j]);
end;

procedure DP;
var i, j: longint;
begin
 for i:=1 to m do
  for j:=1 to n do
   dp11[i, j]:=max(dp11[i-1, j], dp11[i, j-1])+a[i, j];

 for i:=m downto 1 do
  for j:=1 to n do
   dpm1[i, j]:=max(dpm1[i+1, j], dpm1[i, j-1])+a[i, j];

 for i:=1 to m do
  for j:=n downto 1 do
   dp1n[i, j]:=max(dp1n[i-1, j], dp1n[i, j+1])+a[i, j];

 for i:=m downto 1 do
  for j:=n downto 1 do
   dpmn[i, j]:=max(dpmn[i+1, j], dpmn[i, j+1])+a[i, j];
end;

procedure Work;
var i, j, ans, p1, p2: longint;
begin
 ans:=0;
 for i:=2 to m-1 do
  for j:=2 to n-1 do
   begin
    p1:=dp11[i, j-1]+dpmn[i, j+1]+dpm1[i+1, j]+dp1n[i-1, j];
    p2:=dp11[i-1, j]+dpmn[i+1, j]+dpm1[i, j-1]+dp1n[i, j+1];
    ans:=max(ans, max(p1, p2));
   end;
 writeln(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 DP;
 Work;

 close(input); close(output);
end.
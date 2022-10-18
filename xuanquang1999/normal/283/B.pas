const fi = '';
      fo = '';
      maxN = 200000;
var i, x, n: longint;
    a: array [1..maxN] of longint;
    f: array [-1..1, 1..maxN] of int64;
    //-2 infinity loop
    //-1 undefined

function Dist(k, x: longint): int64;
var res: int64;
    i: longint;
begin
 if f[k, x] <> -1 then exit(f[k, x]);

 f[k, x]:=-2;

 i:=x+a[x]*k;
 if (i < 1) or (i > n) then res:=a[x]
 else if Dist(-k, i) = -2 then res:=-2
 else res:=a[x] + f[-k, i];

 f[k, x]:=res;
 exit(res);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=2 to n do read(a[i]);

 for i:=-1 to 1 do
  for x:=2 to n do f[i, x]:=-1;
 f[-1, 1]:=-2; f[1, 1]:=-2;

 for i:=-1 to 1 do
  if i <> 0 then
   for x:=2 to n do f[i, x]:=Dist(i, x);

 for i:=1 to n-1 do
  if f[-1, 1+i] = -2 then writeln(-1)
  else writeln(i+f[-1, 1+i]);

 close(input); close(output);
end.
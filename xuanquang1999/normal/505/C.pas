uses math;
const fi = '';
      fo = '';
      maxN = 30000;
      lim = 1875;
var d: longint;
    a: array [0..maxN] of longint;
    f: array [0..maxN, 0..lim+20] of longint;

procedure Enter;
var i, x, n: longint;
begin
 readln(n, d);
 for i:=1 to n do
  begin
   read(x);
   inc(a[x]);
  end;
end;

function Find1(n, l: longint): longint;
var res: longint;
begin
 if n > 30000 then exit(0);
 res:=a[n];
 res:=max(res, a[n]+Find1(n+l-1, l-1));
 res:=max(res, a[n]+Find1(n+l, l));
 res:=max(res, a[n]+Find1(n+l+1, l+1));
 exit(res);
end;

procedure Find2;
var i, j, k, ans: longint;
begin
 for i:=0 to maxN do
  for j:=1 to lim+20 do f[i, j]:=-10000;

 f[d, d]:=a[d];
 for i:=d to maxN do
  for j:=1 to lim+20 do
   if f[i, j] > -10000 then
    begin
     for k:=-1 to 1 do
      begin
       if (j+k > 0) and (i+j+k < maxN+1) then
       f[i+j+k, j+k]:=max(f[i+j+k, j+k], a[i+j+k]+f[i, j]);
      end;
    end;

 ans:=0;
 for i:=0 to maxN do
  for j:=1 to lim+20 do
   ans:=max(ans, f[i, j]);
 writeln(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 if d > lim then writeln(Find1(d, d))
 else Find2;

 close(input); close(output);
end.
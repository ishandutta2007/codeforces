const fi = '';
      fo = '';
      maxN = 2000;
var n, i, j, k, u: longint;
    cnt: array [-200..200, 0..200] of longint;
    sum: int64;
    x, y, a, b: array [1..maxN] of longint;

function GCD(a, b: longint): longint;
begin
 if b = 0 then exit(a);
 exit(GCD(b, a mod b));
end;

function trinum(a: longint): longint;
begin
 exit((a*(a+1)) div 2);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do readln(x[i], y[i]);

 if n < 3 then
  begin
   writeln(0);
   close(input); close(output);
   halt;
  end;

 for i:=1 to n do
  begin
   a[i]:=0; b[i]:=0;
   for j:=1 to n do
    if j <> i then
     begin
      a[j]:=x[j]-x[i]; b[j]:=y[j]-y[i];
      if b[j] < 0 then
       begin
        a[j]:=-a[j]; b[j]:=-b[j];
       end;
      u:=GCD(abs(a[j]), abs(b[j]));
      a[j]:=a[j] div u; b[j]:=b[j] div u;
      inc(cnt[a[j], b[j]]);
     end;

   cnt[1, 0]:=cnt[1, 0]+cnt[-1, 0]; cnt[-1, 0]:=0;
   for k:=-100 to 100 do
    for j:=0 to 100 do
     if cnt[k, j] <> 0 then
      begin
       if cnt[k, j] > 1 then sum:=sum-trinum(cnt[k, j]-1);
       cnt[k, j]:=0;
      end;

   sum:=sum+trinum(n-2);
  end;

 writeln(sum div 3);

 close(input); close(output);
end.
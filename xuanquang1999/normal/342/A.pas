const fi = '';
      fo = '';
      maxN = 99999;
var n, i, k: longint;
    a: array [1..maxN] of longint;
    cnt: array [1..7] of longint;
    x, y, z: array [1..maxN div 3] of longint;

function Split(a, b, c: longint): boolean;
begin
 if (cnt[a] = 0) or (cnt[b] = 0) or (cnt[c] = 0) then exit(false);
 inc(k);
 x[k]:=a; y[k]:=b; z[k]:=c;
 dec(cnt[a]); dec(cnt[b]); dec(cnt[c]);
 exit(true);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do
  begin
   read(a[i]);
   inc(cnt[a[i]]);
  end;

 while Split(1, 3, 6) do;
 while Split(1, 2, 6) do;
 while Split(1, 2, 4) do;

 if k < n div 3 then writeln(-1)
 else for i:=1 to k do writeln(x[i], ' ', y[i], ' ', z[i]);

 close(input); close(output);
end.
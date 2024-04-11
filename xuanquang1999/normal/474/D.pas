const fi = '';
      fo = '';
      maxN = 100000;
      e = round(1e9)+7;
var f, pref: array [0..maxN] of longint;
    t, k, i, a, b: longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(t, k);
 for i:=0 to k-1 do f[i]:=1;
 for i:=k to maxN do f[i]:=(f[i-k]+f[i-1]) mod e;

 pref[0]:=0;
 for i:=1 to maxN do pref[i]:=(pref[i-1]+f[i]) mod e;

 for i:=1 to t do
  begin
   readln(a, b);
   writeln((pref[b]+e-pref[a-1]) mod e);
  end;

 close(input); close(output);
end.
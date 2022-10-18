const fi = '';
      fo = '';
      maxN = 55;
var i, n: longint;
    k: int64;
    f: array [1..maxN] of int64;
    ans: array [1..maxN] of int64;

procedure EndProg;
begin
 close(input); close(output);
 halt;
end;

procedure Solve(k, i, j: int64);
begin
 if j > n then exit;
 if k > f[i-1] then
  begin
   ans[j]:=j+1;
   ans[j+1]:=j;
   Solve(k-f[i-1], i-2, j+2);
  end
 else
  begin
   ans[j]:=j;
   Solve(k, i-1, j+1);
  end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, k);
 f[1]:=1;
 f[2]:=1;
 for i:=3 to n+1 do f[i]:=f[i-2]+f[i-1];

 Solve(k, i, 1);

 for i:=1 to n do write(ans[i], ' ');

 close(input); close(output);
end.
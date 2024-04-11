uses math;
const fi = '';
      fo = '';
      e = round(1e9)+7;
var n, k, d, i, j: longint;
    dp: array [0..105, 0..1] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, k, d);

 dp[0, 0]:=1;
 for i:=1 to n do
  begin
   for j:=max(0, i-d+1) to i-1 do
    begin
     dp[i, 0]:=(dp[i, 0]+dp[j, 0]) mod e;
     dp[i, 1]:=(dp[i, 1]+dp[j, 1]) mod e;
    end;
   for j:=max(0, i-k) to i-d do
    dp[i, 1]:=((dp[i, 1]+dp[j, 0]) mod e + dp[j, 1]) mod e;
  end;

 writeln(dp[n, 1]);

 close(input); close(output);
end.
const fi = '';
      fo = '';
      maxN = 100000;
var i, j, n: longint;
    curp, x: int64;
    p: array [1..maxN] of int64;
    cost, cnt: array [1..5] of int64;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(p[i]);
 for i:=1 to 5 do read(cost[i]);

 curp:=0;
 for i:=1 to n do
  begin
   curp:=curp+p[i];
   for j:=5 downto 1 do
    begin
     x:=curp div cost[j];
     curp:=curp - x*cost[j];
     cnt[j]:=cnt[j]+x;
    end;
  end;

 for i:=1 to 5 do write(cnt[i], ' ');
 writeln;
 writeln(curp);

 close(input); close(output);
end.
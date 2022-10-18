const fi = '';
      fo = '';
      maxN = 500;
      maxM = 1000;
var n, m, sumW, Top: longint;
    w: array [1..maxN] of longint;
    b: array [1..maxM] of longint;
    Stack: array [1..maxN] of longint;

procedure Enter;
var i: longint;
begin
 readln(n, m);
 for i:=1 to n do read(w[i]);
 for i:=1 to m do read(b[i]);
end;

procedure Push(v: longint);
begin
 inc(Top); Stack[Top]:=v;
end;

procedure CreateStack;
var i: longint;
    free: array [1..maxN] of boolean;
begin
 fillchar(free, sizeof(free), true);
 for i:=1 to m do
  if free[b[i]] then
   begin
    free[b[i]]:=false;
    Push(b[i]);
   end;
 for i:=1 to n do
  if free[i] then Push(i);
end;

procedure CalcSumW;
var i, j, k, tmp: longint;
begin
 for i:=1 to m do
  begin
   for k:=1 to n do
    if Stack[k] = b[i] then break
    else sumW:=sumW + w[Stack[k]];
   tmp:=Stack[k];
   for j:=k downto 2 do Stack[j]:=Stack[j-1];
   Stack[1]:=tmp;
  end;
end;

procedure Answer;
begin
 writeln(sumW);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 CreateStack;
 CalcSumW;
 Answer;

 close(input); close(output);
end.
uses math;
const fi = 'input.txt';
      fo = 'output.txt';
      maxN = 100000;
var n, ans, top: longint;
    a, stack, tdeath: array [1..maxN] of longint;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
end;

procedure Work;
var i: longint;
begin
 tdeath[1]:=-1; top:=1; stack[1]:=1;
 ans:=0;
 for i:=2 to n do
  begin
   while (top > 0) and (a[stack[top]] < a[i]) do
    begin
     tdeath[i]:=max(tdeath[i], tdeath[stack[top]]+1);
     stack[top]:=0; dec(top);
    end;
   if top = 0 then tdeath[i]:=-1;
   inc(top); stack[top]:=i;
   ans:=max(ans, tdeath[i]+1);
  end;
end;

procedure Answer;
begin
 writeln(ans);
end;

begin
 Enter;
 Work;
 Answer;

 close(input); close(output);
end.
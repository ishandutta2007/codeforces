const fi = '';
      fo = '';
      maxN = 100000;
var s: string;
    n, top, i: longint;
    stack: array [1..maxN] of char;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(s);
 n:=length(s);

 i:=1; top:=0;
 while i <= n do
  begin
   inc(top); stack[top]:=s[i]; inc(i);
   while (top >= 2) and (stack[top] = stack[top-1]) do top:=top-2;
  end;

 if top = 0 then writeln('Yes')
 else writeln('No');

 close(input); close(output);
end.
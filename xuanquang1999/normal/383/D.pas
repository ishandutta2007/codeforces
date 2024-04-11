const fi = '';
      fo = '';
      e = round(1e9)+7;
      maxN = 1000;
      maxX = 10000;
var i, j, n, ans: longint;
    a: array [1..maxN] of longint;
    f: array [0..maxN, -maxX..maxX] of longint;

procedure EndProg;
begin
 close(input); close(output);
 halt;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(a[i]);

 //f[0, 0]:=1;
 for i:=1 to n do
  begin
   for j:=-maxX to maxX-a[i] do f[i, j]:=(f[i, j]+f[i-1, j+a[i]]) mod e;
   for j:=-maxX+a[i] to maxX do f[i, j]:=(f[i, j]+f[i-1, j-a[i]]) mod e;
   f[i, a[i]]:=(f[i, a[i]]+1) mod e;
   f[i, -a[i]]:=(f[i, -a[i]]+1) mod e;
  end;

 ans:=0;
 for i:=1 to n do ans:=(ans+f[i, 0]) mod e;

 writeln(ans);

 close(input); close(output);
end.
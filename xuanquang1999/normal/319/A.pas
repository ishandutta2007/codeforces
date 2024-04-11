const fi = '';
      fo = '';
      e = round(1e9)+7;
      maxN = 100;
var n: Qword;
    x: string;
    p2: array [0..maxN] of Qword;
    ans: Qword;

procedure Enter;
var i: longint;
begin
 readln(x);
 n:=length(x);
 p2[0]:=1;
 for i:=1 to n do
  p2[i]:=(p2[i-1]*2) mod e;
end;


procedure Work;
var i: longint;
begin
 ans:=0;
 for i:=1 to n do
  if x[i] = '1' then ans:=(ans+p2[n-i]) mod e;
 ans:=(ans*p2[n-1]) mod e;
 writeln(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
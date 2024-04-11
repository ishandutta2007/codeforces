const fi = '';
      fo = '';
      maxN = 1000000;
      m = round(1e9)+7;
var fact: array [0..maxN] of Qword;
    a, b, n: longint;
    ans: Qword;

procedure CalcFact;
var i: longint;
begin
 fact[0]:=1;
 for i:=1 to n do
  fact[i]:=(fact[i-1]*i) mod m;
end;

function isGood(n: longint): boolean;
var p: longint;
begin
 while n > 0 do
  begin
   p:=n mod 10;
   if (p <> a) and (p <> b) then exit(false);
   n:=n div 10;
  end;
 exit(true);
end;

function powmod(a, n: Qword): Qword;
var p: Qword;
begin
 if n = 1 then exit(a)
 else
  begin
   p:=powmod(a, n div 2) mod m;
   if n mod 2 = 0 then exit(sqr(p) mod m)
   else exit((powmod(a, n-1)*a) mod m);
  end;
end;

function C(k, n: longint): Qword;
var ans: Qword;
begin
 ans:=fact[n]*powmod((fact[k]*fact[n-k]) mod m, m-2);
 exit(ans mod m);
end;

procedure Work;
var i: longint;
begin
 ans:=0;
 for i:=0 to n do
  if isGood(a*i+b*(n-i)) then
   begin
    ans:=(ans+C(i, n)) mod m;
   end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(a, b, n);
 CalcFact;
 Work;
 writeln(ans);

 close(input); close(output);
end.
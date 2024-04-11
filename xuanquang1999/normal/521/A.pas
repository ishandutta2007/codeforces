const fi = '';
      fo = '';
      maxN = 100005;
      e = round(1e9)+7;
type mang = array [1..100005] of longint;
var i, j, n, tmp: longint;
    c: array [1..4] of int64;
    ch: char;
    ans: int64;

function pow(a, n: int64): int64;
var p, tmp: int64;
begin
 if n = 0 then exit(1)
 else
  begin
   p:=pow(a, n div 2);
   if n mod 2 = 0 then tmp:=sqr(p) mod e
   else tmp:=((sqr(p) mod e) * a) mod e;
   exit(tmp);
  end;
end;

function Cnk(n, k: int64): int64;
var c1, c2: mang;
    ans: int64;
    i: longint;
    procedure Ptich(n: longint; var c: mang);
    var i, l: longint;
    begin
     l:=trunc(sqrt(n));
     for i:=2 to l do
      while n mod i = 0 do
       begin
        inc(c[i]);
        n:=n div i;
       end;
     if n > l then inc(c[n]);
    end;
begin
 fillchar(c1, sizeof(c1), 0);
 fillchar(c2, sizeof(c2), 0);
 for i:=2 to n do Ptich(i, c1);
 for i:=2 to k do Ptich(i, c2);
 for i:=2 to n-k do Ptich(i, c2);
 ans:=1;
 for i:=2 to n do
  ans:=(ans*pow(i, c1[i]-c2[i])) mod e;
 exit(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do
  begin
   read(ch);
   case ch of
    'A': inc(c[1]);
    'G': inc(c[2]);
    'T': inc(c[3]);
    'C': inc(c[4]);
   end;
  end;

 for i:=1 to 3 do
  for j:=i+1 to 4 do
   if c[i] > c[j] then
    begin
     tmp:=c[i];
     c[i]:=c[j];
     c[j]:=tmp;
    end;

 i:=4;
 while i > 1 do
  begin
   if c[i-1] < c[i] then break;
   dec(i);
  end;

 writeln(pow(4-i+1, n));

 close(input); close(output);
end.
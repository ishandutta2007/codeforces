const fi = '';
      fo = '';
      maxN = 100000;
      e = round(1e9)+7;
var n, i, j: longint;
    s, t: string;
    f00, f01, f10, f11: array [0..maxN] of int64;
    //00 contain no position that s[i] <> t[i]
    //01 contain atleast 1 position that s[i] > t[i]
    //10 contain atleast 1 position that t[i] > s[i]
    //11 contain atleast 1 position that s[i] > t[i] and 1 position that t[i] > s[i]

function Num(c: char): int64;
begin
 exit(ord(c)-48);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 readln(s);
 readln(t);

 f00[0]:=1;
 for i:=1 to n do
  if (s[i] = '?') and (t[i] = '?') then
   begin
    f00[i]:=(f00[i-1]*10) mod e;
    f01[i]:=(f00[i-1]*45 + f01[i-1]*55) mod e;
    f10[i]:=(f00[i-1]*45 + f10[i-1]*55) mod e;
    f11[i]:=(f11[i-1]*100 + (f10[i-1]+f01[i-1])*45) mod e;
   end
  else if (s[i] = '?') then
   begin
    f00[i]:=f00[i-1];
    f01[i]:=(f00[i-1]*(9-Num(t[i])) + f01[i-1]*(10-Num(t[i]))) mod e;
    f10[i]:=(f00[i-1]*Num(t[i]) + f10[i-1]*(Num(t[i])+1)) mod e;
    f11[i]:=(f11[i-1]*10 + f10[i-1]*(9-Num(t[i])) + f01[i-1]*Num(t[i])) mod e;
   end
  else if (t[i] = '?') then
   begin
    f00[i]:=f00[i-1];
    f01[i]:=(f00[i-1]*Num(s[i]) + f01[i-1]*(Num(s[i])+1)) mod e;
    f10[i]:=(f00[i-1]*(9-Num(s[i])) + f10[i-1]*(10-Num(s[i]))) mod e;
    f11[i]:=(f11[i-1]*10 + f10[i-1]*Num(s[i]) + f01[i-1]*(9-Num(s[i]))) mod e;
   end
  else if (s[i] < t[i]) then
   begin
    f00[i]:=0;
    f01[i]:=0;
    f10[i]:=f00[i-1]+f10[i-1];
    f11[i]:=f01[i-1]+f11[i-1];
   end
  else if (s[i] > t[i]) then
   begin
    f00[i]:=0;
    f01[i]:=f00[i-1]+f01[i-1];
    f10[i]:=0;
    f11[i]:=f10[i-1]+f11[i-1];
   end
  else //s[i] = t[i]
   begin
    f00[i]:=f00[i-1];
    f01[i]:=f01[i-1];
    f10[i]:=f10[i-1];
    f11[i]:=f11[i-1];
   end;

 writeln(f11[n]);

 close(input); close(output);
end.
const fi = '';
      fo = '';
      maxN = 500000;
var isVowel: array [1..maxN] of boolean;
    d: array [0..maxN] of longint;
    n: longint;
    ans: double;
    sum: Qword;

procedure Enter;
var c: char;
begin
 while not eoln do
  begin
   read(c);
   inc(n);
   case c of
    'I', 'E', 'A', 'O', 'U', 'Y': isVowel[n]:=true
    else isVowel[n]:=false;
   end;
  end;
end;

procedure Calc_f;
var i: longint;
begin
 d[0]:=0;
 for i:=1 to n do
  if isVowel[i] then d[i]:=d[i-1]+1
  else d[i]:=d[i-1];
end;

procedure Work;
var i: longint;
begin
 sum:=0; ans:=0;
 for i:=1 to n div 2 do
  begin
   sum:=sum+d[n-i+1]-d[i-1];
   ans:=ans+sum/i+sum/(n-i+1);
  end;
 if n mod 2 = 1 then
  begin
   if isVowel[n div 2 + 1] then sum:=sum+1;
   ans:=ans+sum/(n div 2 + 1);
  end;
 writeln(ans:0:7);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Calc_F;
 Work;

 close(input); close(output);
end.
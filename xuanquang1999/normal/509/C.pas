uses math;
const fi = '';
      fo = '';
      maxN = 300;
      maxD = 1000;
type bigNum = array [0..maxD] of longint;
var i, n: longint;
    a: array [0..maxN] of longint;
    b: array [0..maxN] of bigNum;

procedure PrintBigNum(a: bigNum);
var i: longint;
begin
 for i:=a[0] to maxD do write(a[i]);
 writeln;
end;

function Solve(a: bigNum; sumA, sumB: longint): bigNum;
var i, n: longint;
    b: bigNum;
    done: boolean;
begin
 i:=maxD; done:=false;
 while (sumA > sumB) or ((sumA = sumB) and not done) do
  begin
   done:=true;
   sumA:=sumA-a[i]+1; a[i]:=0; inc(a[i-1]);
   dec(i);
   while (a[i] = 10) do
    begin
     inc(a[i-1]);
     a[i]:=0;
     sumA:=sumA-9;
     dec(i);
    end;
  end;
 a[0]:=min(a[0], i);

 b:=a;

 if sumB > sumA then
  begin
   for i:=maxD downto b[0] do
    begin
     b[i]:=b[i]+min(9-b[i], sumB-sumA);
     sumB:=sumB-(b[i]-a[i]);
     if sumB = sumA then break;
    end;
   while sumB > sumA do
    begin
     dec(b[0]);
     b[b[0]]:=min(9, sumB-sumA);
     sumB:=sumB-b[b[0]];
    end;
  end;

 exit(b);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 a[0]:=0; b[0][0]:=maxD; b[0][maxD]:=0;
 for i:=1 to n do
  begin
   readln(a[i]);
   b[i]:=Solve(b[i-1], a[i-1], a[i]);
   PrintBigNum(b[i]);
  end;

 close(input); close(output);
end.
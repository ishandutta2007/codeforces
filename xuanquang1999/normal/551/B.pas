uses math;
const fi = '';
      fo = '';
var a, b, c: string;
    cntA, cntB, cntC: array ['a'..'z'] of longint;
    i, nA, nB, nC, ansB, ansC: longint;
    ch: char;

procedure Work;
var ch: char;
    i, cur, maxC: longint;
begin
 maxC:=0;
 for i:=0 to nA div nB do
  begin
   cur:=nA;
   for ch:='a' to 'z' do
    begin
     if cntA[ch] < i*cntB[ch] then exit;
     if cntC[ch] > 0 then cur:=min(cur, (cntA[ch]-i*cntB[ch]) div cntC[ch]);
    end;

   if cur+i > maxC then
    begin
     ansB:=i;
     ansC:=cur;
     maxC:=ansB+ansC;
    end;
  end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(a); nA:=length(a);
 readln(b); nB:=length(b);
 readln(c); nC:=length(c);
 for i:=1 to nA do inc(cntA[a[i]]);
 for i:=1 to nB do inc(cntB[b[i]]);
 for i:=1 to nC do inc(cntC[c[i]]);

 Work;

 for ch:='a' to 'z' do
  cntA[ch]:=cntA[ch]-ansB*cntB[ch]-ansC*cntC[ch];
 for i:=1 to ansB do write(b);
 for i:=1 to ansC do write(c);
 for ch:='a' to 'z' do
  for i:=1 to cntA[ch] do write(ch);
 writeln;

 close(input); close(output);
end.
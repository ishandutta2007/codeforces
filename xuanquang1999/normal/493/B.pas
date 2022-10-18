uses math;
const fi = '';
      fo = '';
      maxN = 200000+5;
      oo = maxlongint;
var a, b: array [1..maxN] of longint;
    na, nb, k: longint;

procedure Enter;
var i, n: longint;
begin
 for i:=1 to maxN do
  begin
   a[i]:=-oo; b[i]:=-oo;
  end;

 na:=0; nb:=0;
 readln(n);
 for i:=1 to n do
  begin
   readln(k);
   if k > 0 then
    begin
     inc(na);
     a[na]:=k;
    end
   else
    begin
     inc(nb);
     b[nb]:=-k;
    end;
  end;
end;

function Answer: string;
var i: longint;
    suma, sumb: Qword;
begin
 suma:=0; sumb:=0;
 for i:=1 to na do suma:=suma + a[i];
 for i:=1 to nb do sumb:=sumb + b[i];
 if suma > sumb then exit('first');
 if suma < sumb then exit('second');

 for i:=1 to max(na, nb) do
  if a[i] > b[i] then exit('first')
  else if a[i] < b[i] then exit('second');

 if k > 0 then exit('first')
 else exit('second');
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 writeln(Answer);

 close(input); close(output);
end.
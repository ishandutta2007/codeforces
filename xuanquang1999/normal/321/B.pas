uses math;
const fi = '';
      fo = '';
      maxN = 100+5;
      maxA = round(1e9);
type CardArr = array [1..maxN] of longint;
var n, AtkCount, DefCount, m: longint;
    t: array [1..maxN] of string;
    Atk, Def, Fox: CardArr;

procedure Sort(var a: CardArr; n: longint);
var i, j, tmp: longint;
begin
 for i:=1 to n-1 do
  for j:=i+1 to n do
   if a[i] > a[j] then
    begin
     tmp:=a[i];
     a[i]:=a[j];
     a[j]:=tmp;
    end;
end;

procedure Enter;
var i, p: longint;
    s, t: string;
    code: integer;
begin
 readln(n, m);
 for i:=1 to n do
  begin
   readln(s);
   t:=copy(s, 1, 3);
   val(copy(s, 5, length(s)-4), p, code);
   if t = 'ATK' then
    begin
     inc(AtkCount);
     Atk[AtkCount]:=p;
    end
   else
    begin
     inc(DefCount);
     Def[DefCount]:=p;
    end
  end;
 for i:=1 to m do readln(Fox[i]);

 Sort(Atk, AtkCount);
 Sort(Def, DefCount);
 Sort(Fox, m);
end;

function KillAll: longint;
var i, j, sum: longint;
    isUsed: array [1..maxN] of boolean;
begin
 fillchar(isUsed, sizeof(isUsed), false);
 j:=1;
 for i:=1 to DefCount do
  begin
   while (j <= m) and (Fox[j] <= Def[i]) do inc(j);
   if j > m then exit(0);
   isUsed[j]:=true; inc(j);
  end;

 sum:=0;
 j:=1;
 for i:=1 to AtkCount do
  begin
   while (j <= m) and (isUsed[j] or (Fox[j] < Atk[i])) do inc(j);
   if j > m then exit(0);
   sum:=sum+Fox[j]-Atk[i];
   isUsed[j]:=true; inc(j);
  end;
 for i:=m downto 1 do
  if not isUsed[i] then sum:=sum + Fox[i];
 exit(sum);
end;

function KillAtk: longint;
var i, j, sum: longint;
begin
 sum:=0;
 if AtkCount > 0 then
  begin
   i:=1;
   for j:=m downto 1 do
    begin
     if Fox[j] < Atk[i] then exit(sum);
     sum:=sum + (Fox[j]-Atk[i]);
     inc(i); if i > AtkCount then break;
    end;
  end
 else j:=m+1;
 exit(sum);
end;

procedure Work;
begin
 writeln(max(KillAtk, KillAll));
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
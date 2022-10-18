const fi = '';
      fo = '';
      maxN = 100000;
      maxD = 8;
var a: array [0..maxN] of string;
    x: array [0..maxN] of longint;
    e10: array [0..maxD] of longint;
    n: longint;

function toStr(x: longint): string;
var s: string;
begin
 str(x, s);
 exit(s);
end;

function toNum(s: string): longint;
var code: integer;
    x: longint;
begin
 val(s, x, code);
 exit(x);
end;



procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do readln(a[i]);
 x[0]:=0;
end;

procedure Calc_e10;
var i: longint;
begin
 e10[0]:=1;
 for i:=1 to 8 do e10[i]:=e10[i-1]*10;
end;


function Find(x: longint; s: string): longint;
var count, i, mid, res, L, R: longint;
    function replace(x: longint): longint;
    var s1, s2: string;
        i, j: longint;
    begin
     s1:=s;
     str(x, s2);
     while length(s2) < count do s2:='0'+s2;
     j:=1;
     for i:=1 to length(s1) do
      if s1[i] = '?' then
       begin
        s1[i]:=s2[j];
        inc(j);
       end;
     exit(toNum(s1));
    end;
begin
 count:=0;
 for i:=1 to length(s) do
  if s[i] = '?' then inc(count);
 if s[1] = '?' then L:=e10[count-1]
 else L:=0;
 R:=e10[count]-1;

 res:=e10[maxD]+1;
 while L <= R do
  begin
   mid:=(L+R) div 2;
   if replace(mid) > x then
    begin
     if mid < res then res:=mid;
     R:=mid-1;
    end
   else L:=mid+1;
  end;

 if res = e10[maxD]+1 then exit(-1)
 else exit(replace(res));
end;

procedure Work;
var i: longint;
begin
 for i:=1 to n do
  begin
   x[i]:=Find(x[i-1], a[i]);
   if x[i] = -1 then
    begin
     writeln('NO');
     exit;
    end;
  end;

 writeln('YES');
 for i:=1 to n do writeln(x[i]);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Calc_e10;
 Work;

 close(input); close(output);
end.
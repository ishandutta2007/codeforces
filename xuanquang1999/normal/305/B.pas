{$N+}
const fi = '';
      fo = '';
      maxN = 100;
type xau = ansistring;
var p, q: Qword;
    a: array [1..maxN] of Qword;
    n: longint;


procedure Enter;
var i: longint;
begin
 readln(p, q);
 readln(n);
 for i:=1 to n do read(a[i]);
end;

procedure SwapS(var a, b: xau);
var t: xau;
begin
 t:=a; a:=b; b:=t;
end;

function toXau(n: Qword): xau;
var s: xau;
begin
 str(n, s);
 exit(s);
end;

function toNum(s: xau): Qword;
var n: Qword;
    code: integer;
begin
 val(s, n, code);
 exit(n);
end;

function bigAdd(a, b: xau): xau;
var c: xau;
    mem, i, p: longint;
begin
 c:=''; mem:=0;
 while length(a) < length(b) do a:='0'+a;
 while length(b) < length(a) do b:='0'+b;
 for i:=length(a) downto 1 do
  begin
   p:=toNum(a[i]) + toNum(b[i]) + mem;
   mem:=p div 10; p:=p mod 10;
   c:=toXau(p) + c;
  end;
 if mem > 0 then c:=toXau(mem) + c;
 exit(c);
end;

function bigMulti1(a: xau; k: Qword): xau;
var c: xau;
    i: longint;
    p, mem: Qword;
begin
 c:=''; mem:=0;
 for i:=length(a) downto 1 do
  begin
   p:=toNum(a[i])*k + mem;
   mem:=p div 10; p:=p mod 10;
   c:=toXau(p) + c;
  end;
 if mem > 0 then c:=toXau(mem) + c;
 exit(c);
end;

function bigMulti2(a, b: xau): xau;
var c, s: xau;
    i, j: longint;
begin
 c:='';
 for i:=length(b) downto 1 do
  begin
   s:=bigMulti1(a, toNum(b[i]));
   for j:=1 to length(b)-i do s:=s + '0';
   c:=c+s;
  end;
 exit(c);
end;

procedure Work;
var i: longint;
    tu, mau: xau;
begin
 str(a[n], tu); mau:='1';
 for i:=n-1 downto 1 do
  begin
   SwapS(tu, mau);
   tu:=bigAdd(bigMulti1(mau, a[i]), tu);
  end;

 if bigMulti1(tu, q) = bigMulti1(mau, p) then writeln('YES')
 else writeln('NO');
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
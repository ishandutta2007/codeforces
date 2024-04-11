uses math;
const fi = '';
      fo = '';
var n, m, x, y, a, b: longint;
    p, m1, n1, x1, x2, y1, y2: longint;

procedure Enter;
begin
 readln(n, m, x, y, a, b);
end;

function GCD(a, b: longint): longint;
begin
 if b = 0 then exit(a);
 exit(GCD(b, a mod b));
end;

procedure Find(var x1, x2: longint; m, m1, x: longint);
begin
 if x <= m1 div 2 then
  begin
   x1:=0; x2:=m1;
   exit;
  end;
 if x >= (m - m1 div 2) then
  begin
   x1:=m - m1; x2:=m;
   exit;
  end;
 if m1 mod 2 = 0 then x1:=x - m1 div 2
 else x1:=x - (m1+1) div 2;
 x2:=x1+m1;
end;

procedure Work;
var u: longint;
begin
 u:=GCD(a, b);
 a:=a div u; b:=b div u;
 p:=min(n div a, m div b);
 n1:=a*p; m1:=b*p;

 Find(x1, x2, n, n1, x);
 Find(y1, y2, m, m1, y);
end;

procedure Answer;
begin
 writeln(x1, ' ', y1, ' ', x2, ' ', y2);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.
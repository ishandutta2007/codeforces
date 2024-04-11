const fi = '';
      fo = '';
      maxN = 101;
var i, n, m, u: longint;
    p, q: array [1..maxN] of longint;

function GCD(a, b: longint): longint;
begin
 if b = 0 then exit(a);
 exit(GCD(b, a mod b));
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, m);
 for i:=1 to n+1 do read(p[i]);
 for i:=1 to m+1 do read(q[i]);

 if n > m then
  begin
   if p[1]*q[1] < 0 then write('-');
   writeln('Infinity');
  end
 else if n < m then writeln('0/1')
 else
  begin
   u:=GCD(p[1], q[1]);
   p[1]:=p[1] div u; q[1]:=q[1] div u;
   if q[1] < 0 then
    begin
     q[1]:=-q[1]; p[1]:=-p[1];
    end;
   writeln(p[1], '/', q[1]);
  end;

 close(input); close(output);
end.
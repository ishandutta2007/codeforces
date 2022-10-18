const maxN = 30000;
var n, t, i: longint;
    a: array [1..maxN] of longint;


begin
 readln(n, t);
 for i:=1 to n-1 do read(a[i]);

 i:=1;
 while (i <> t) and (i < n) do
  begin
   i:=i+a[i];
  end;
 if i = t then writeln('YES')
 else writeln('NO');
end.
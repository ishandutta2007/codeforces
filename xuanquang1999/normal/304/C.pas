var n, i: longint;
    a, b, c: array [1..100000] of longint;

begin
 readln(n);
 if n mod 2 = 0 then writeln(-1)
 else
  begin
   for i:=1 to n do
    begin
     a[i]:=i-1;
     b[i]:=i-1;
     c[i]:=(a[i]+b[i]) mod n;
    end;
   for i:=1 to n do write(a[i], ' '); writeln;
   for i:=1 to n do write(b[i], ' '); writeln;
   for i:=1 to n do write(c[i], ' '); writeln;
  end;
end.
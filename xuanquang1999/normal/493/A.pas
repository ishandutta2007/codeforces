const fi = '';
      fo = '';
      maxN = 100;
var h, a: array [1..maxN] of longint;
    n, t, num, i: longint;
    sh, sa: string;
    d, the, tmp: char;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(sh);
 readln(sa);
 readln(n);
 for i:=1 to n do
  begin
   readln(t, tmp, d, num, tmp, the);
   if the = 'r' then
    begin
     if d = 'h' then
      begin
       if h[num] < 2 then writeln(sh, ' ', num, ' ', t);
       h[num]:=h[num] + 2;
      end
     else
      begin
       if a[num] < 2 then writeln(sa, ' ', num, ' ', t);
       a[num]:=a[num] + 2;
      end;
    end
   else
    begin
     if d = 'h' then
      begin
       inc(h[num]);
       if h[num] = 2 then writeln(sh, ' ', num, ' ', t);
      end
     else
      begin
       inc(a[num]);
       if a[num] = 2 then writeln(sa, ' ', num, ' ', t);
      end
    end;
  end;

 close(input); close(output);
end.
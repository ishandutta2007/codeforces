var                  
  n, m, i : longint;       

  function gcd(x, y : longint) : longint;
    begin 
      while (x > 0) and (y > 0) do 
        if (x > y) then x := x mod y else y := y mod x;
      gcd := x + y;
    end;

  function f(x, y : longint) : longint;
    var
      r : longint;

    begin
      r := 0;
      while (x > 0) do begin
        inc(r, x mod y);
        x := x div y;
      end;
      f := r;
    end;

begin
  read(n);
  m := 0;
  for i:=2 to n-1 do 
    inc(m, f(n, i));
  n := n-2;
  i := gcd(n, m);
  writeln(m div i, '/', n div i);
end.
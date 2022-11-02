var
  a, b : longint;

  function GCD(a, b : longint) : longint;
    begin
      while (a > 0) and (b > 0) do
        if (a > b) then a := a mod b else b := b mod a;
      GCD := a + b;
    end;

begin
  read(a, b);
  if (b > a) then a := b;
  a := 6 - a + 1;
  if (a = 0) then writeln('0/1') else begin
    b := GCD(a, 6);  
    writeln(a div b, '/', 6 div b);
  end;
end.
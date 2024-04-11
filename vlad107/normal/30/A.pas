{$r-,q-,s-,i-,o+}
var
  n, a, b, x, i, j : longint;

  procedure bad;
    begin
      writeln('No solution');
      halt(0);
    end;

begin
  read(a, b, n);
  if (a = 0) and (b <> 0) then bad;
  if (a = 0) and (b = 0) then begin
    writeln(0);
    exit;
  end;
  if (b mod a <> 0) then bad;
  a := b div a;
  for i:=-1000 to 1000 do begin
    x := 1;
    for j:=1 to n do begin
      x := x * i;
      if (abs(x) > abs(a)) then break;
    end;
    if (x = a) then begin
      writeln(i);
      exit;
    end;
  end;
  bad;
end.
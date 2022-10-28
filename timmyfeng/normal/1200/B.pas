function max(a, b : longint) : longint;
  begin
    if a > b then
      max := a
    else
      max := b
  end;

var
  t, tt : longint;
  n, k, i, a, bag, prv : longint;
  ok : boolean;

begin
  read(t);

  for tt := 1 to t do
    begin
      read(n, bag, k);
      ok := true;
      prv := 0;

      for i := 1 to n do
        begin
          read(a);
          if i > 1 then
            inc(bag, prv - max(0, a - k));
          prv := a;
          if bag < 0 then
            ok := false;
        end;

      if ok then
        writeln('Yes')
      else
        writeln('No');
    end;
end.
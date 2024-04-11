var
  n, res : longint;

  procedure rec(x : int64);
    begin
      if (x > n) then exit;
      inc(res);
      rec(x*10);
      rec(x*10 + 1);
    end;

begin
  read(n);
  res := 0;
  rec(1);
  writeln(res);
end.
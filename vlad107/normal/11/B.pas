{$r-,q-,s-,i-,o+}
var
  i, n : longint;
  s    : int64;

begin
  read(n);
  n := abs(n);
  if (n = 0)
    then begin
      writeln(0);
      exit;
    end;
  s := 0;
  for i:=0 to 100000 do begin
    inc(s, i+1);
    if (n <= s) and (((i and 3 < 2) and (n and 1 > 0)) or ((i and 3 > 1) and (n and 1 = 0)))
      then begin
        writeln(i+1);
        break;
      end;
  end;
end.
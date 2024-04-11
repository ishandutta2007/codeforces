var
  n, i : longint;
  s : string;
  c : char;
  full : array[0..9] of boolean;

begin
  readln(n);
  read(s);

  for i := 0 to 9 do
    full[i] := false;

  for c in s do
    begin
      if c = 'L' then
        begin
          i := 0;
          while full[i] do inc(i);
        end
      else if c = 'R' then
        begin
          i := 9;
          while full[i] do dec(i);
        end
      else
        i := ord(c) - ord('0');
      full[i] := full[i] xor true;
    end;

  for i := 0 to 9 do
    if full[i] then
      write(1)
    else
      write(0);

  writeln;
end.
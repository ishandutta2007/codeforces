const
  BAD = 'WRONG_ANSWER';

var
  a,b : string;
  ch  : char;
  i   : longint;
  k   : array ['0'..'9'] of longint;

begin
  readln(a);
  readln(b);
  if (length(b) <> length(a))
    then begin
      writeln(BAD);
      exit;
    end;
  if (a = b) and (a = '0') then begin
    writeln('OK');
    exit;
  end;
  fillchar(k, sizeof(k), $0);
  for i:=1 to length(a) do inc(k[a[i]]);
  for i:=1 to length(b) do begin
    ch := '0';
    if (i = 1) then ch := '1';
    while (ch <= '9') and (k[ch] = 0)
      do ch := chr(ord(ch) + 1);
    if (ch <> b[i]) then begin
      writeln(BAD);
      exit;
    end;
    dec(k[ch]);
  end;
  writeln('OK');
end.
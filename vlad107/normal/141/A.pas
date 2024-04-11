var
  s:ansistring;
  i:longint;
  ch:char;
  kch:array[#0..#255]of longint;

begin
  fillchar(kch,sizeof(kch),$0);
  readln(s);
  for i:=1 to length(s)do inc(kch[s[i]]);
  readln(s);
  for i:=1 to length(s)do inc(kch[s[i]]);
  readln(s);
  for i:=1 to length(s)do dec(kch[s[i]]);
  for ch:=#0 to #255 do 
    if (kch[ch]<>0)then begin
      writeln('NO');
      exit;
    end;
  writeln('YES');
end.
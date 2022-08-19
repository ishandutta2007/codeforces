{$R-,S-,Q-,I-,O+}
var
  s,t: ansistring;
  n,m,i,j,q,bad: longint;
  ch,cc: char;
  ns: array [0..50010] of char;
  c: array ['a'..'z'] of longint;
begin
  readln(s);
  readln(t);
  n:=length(s);
  m:=length(t);
  while m < n do
  begin
    t:=t+' ';
    inc(m);
  end;
  fillchar(c,sizeof(c),0);
  for i:=1 to length(s) do inc(c[s[i]]);
  for i:=1 to n do
  begin
    ns[i]:=' ';
    for ch:='a' to 'z' do
    begin
      if c[ch] = 0 then continue;
      if ch < t[i] then continue;
      if ch > t[i] then
      begin
        ns[i]:=ch;
        dec(c[ch]);
        j:=i;
        for cc:='a' to 'z' do
          for q:=1 to c[cc] do
          begin
            inc(j);
            ns[j]:=cc;
          end;
        for j:=1 to n do write(ns[j]);
        writeln;
        halt;
      end;
      ns[i]:=ch;
      dec(c[ch]);
      j:=i;
      for cc:='z' downto 'a' do
        for q:=1 to c[cc] do
        begin
          inc(j);
          ns[j]:=cc;
        end;
      inc(c[ch]);
      bad:=1;
      for j:=1 to n do
      begin
        if ns[j] < t[j] then begin bad:=1; break; end;
        if ns[j] > t[j] then begin bad:=-1; break; end;
      end;
      for j:=i+1 to n do ns[j]:=' ';
      if bad = 1 then
      begin
        ns[i]:=' ';
        continue;
      end;
      dec(c[ch]);
      break;
    end;
    if ns[i] = ' ' then
    begin
      writeln(-1);
      halt;
    end;
  end;
  for j:=1 to n do write(ns[j]);
  writeln;
end.
{$R+,S+,Q+,I+,O-}
var
  n,i,j,q,c: longint;
  s: string;
  b: array [0..1000010] of boolean;
begin
  read(n);
  for i:=2 to 1000000 do b[i]:=True;
  b[1]:=False;
  for i:=1 to 1000000 do
    if b[i] then
    begin
      c:=i+i;
      while c <= 1000000 do
      begin
        b[c]:=False;
        inc(c,i);
      end;
    end;
  for i:=1 to 1000000 do
  begin
    if not b[i] then continue;
    str(i,s);
    q:=0;
    for j:=length(s) downto 1 do q:=q*10+Ord(s[j])-48;
    if i = q then continue;
    if not b[q] then continue;
    if n = 1 then
    begin
      writeln(i);
      break;
    end;
    dec(n);
  end;
end.
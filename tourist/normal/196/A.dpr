{$R+,S+,Q+,I+,O-}
var
  s: ansistring;
  n,i: longint;
  c: char;
  last: array ['a'..'z'] of longint;
  next: array [0..100010,'a'..'z'] of longint;
begin
  readln(s);
  n:=length(s);
  for c:='a' to 'z' do last[c]:=n+1;
  for i:=n downto 1 do
  begin
    last[s[i]]:=i;
    for c:='a' to 'z' do next[i,c]:=last[c];
  end;
  i:=1;
  while i <= n do
    for c:='z' downto 'a' do
      if next[i,c] <= n then
      begin
        i:=next[i,c]+1;
        write(c);
        break;
      end;
  writeln;
end.
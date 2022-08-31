{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,cur: longint;
  s: ansistring;
  max: array [0..10010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n);
  readln(s);
  for i:=1 to n do
  begin
    max[i]:=1;
    cur:=1;
    for j:=i to n-1 do
      if s[j] = 'R' then break else
      if s[j] = 'L' then inc(cur);
    if cur > max[i] then max[i]:=cur;
    cur:=1;
    for j:=i-1 downto 1 do
      if s[j] = 'L' then break else
      if s[j] = 'R' then inc(cur);
    if cur > max[i] then max[i]:=cur;
  end;
  for i:=1 to n-1 do write(max[i],' ');
  writeln(max[n]);
  close(input);
  close(output);
end.
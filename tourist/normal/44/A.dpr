{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,ans: longint;
  s: array [0..1010] of ansistring;
  tmp: ansistring;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n);
  for i:=1 to n do readln(s[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if s[i] > s[j] then
      begin
        tmp:=s[i]; s[i]:=s[j]; s[j]:=tmp;
      end;
  ans:=1;
  for i:=2 to n do
    if s[i] <> s[i-1] then inc(ans);
  writeln(ans);
  close(input);
  close(output);
end.
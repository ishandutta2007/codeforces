{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,i,j: longint;
  ok: boolean;
  a: array [0..110,0..110] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  ok:=True;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] <> a[i,1] then ok:=False;
  for i:=1 to n-1 do
    if a[i,1] = a[i+1,1] then ok:=False;
  if ok then writeln('YES')
  else writeln('NO');
  close(input);
  close(output);
end.
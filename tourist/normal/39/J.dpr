{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,i,k,p: longint;
  a,b: array [0..1000010] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  n:=0;
  while not eoln(input) do
  begin
    inc(n);
    read(a[n]);
  end;
  readln;
  m:=0;
  while not eoln(input) do
  begin
    inc(m);
    read(b[m]);
  end;
  k:=0;
  for i:=1 to m do
    if a[i] = b[i] then inc(k)
    else break;
  p:=0;
  for i:=m downto 1 do
    if a[i+1] = b[i] then inc(p)
    else break;
  if k+p < m then writeln(0) else
  begin
    writeln(k-(n-p)+2);
    for i:=n-p to k do write(i,' ');
    writeln(k+1);
  end;
  close(input);
  close(output);
end.
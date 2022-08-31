{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const inf = round(1e18);
var
  f: array [0..1510,0..1510] of int64;
  s,a: array [0..1510,0..1510] of longint;
  n,m,i,j: longint;
  ans,max: int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  for i:=1 to n do
  begin
    s[i,1]:=a[i,1];
    for j:=2 to m do s[i,j]:=s[i,j-1]+a[i,j];
  end;
  for i:=1 to m do f[1,i]:=s[1,i];
  for i:=2 to n do
    if i and 1 = 0 then
    begin
      max:=-inf;
      for j:=m downto 1 do
      begin
        f[i,j]:=max+s[i,j];
        if f[i-1,j] > max then max:=f[i-1,j];
      end;
    end else
    begin
      max:=-inf;
      for j:=1 to m do
      begin
        f[i,j]:=max+s[i,j];
        if f[i-1,j] > max then max:=f[i-1,j];
      end;
    end;
  ans:=-inf;
  for j:=1 to m do
    if f[n,j] > ans then ans:=f[n,j];
  writeln(ans);
  close(input);
  close(output);
end.
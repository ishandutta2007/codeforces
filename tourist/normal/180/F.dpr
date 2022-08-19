{$R-,S-,Q-,I-,O+}
var
  n,i,x: longint;
  pz,a: array [0..100010] of longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do pz[a[i]]:=i;
  for i:=1 to n do
  begin
    read(x);
    write(pz[x]);
    if i < n then write(' ');
  end;
  writeln;
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,k,i: longint;
  a: array [0..10010] of longint;
begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  read(n,k);
  for i:=1 to n do read(a[i]);
  while a[k] = 0 do
  begin
    inc(k);
    if k > n then k:=1;
  end;
  writeln(k);
  close(input);
  close(output);
end.
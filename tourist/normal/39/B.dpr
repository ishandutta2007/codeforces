{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a,b: array [0..100010] of longint;
  n,i,x: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  x:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i] = x+1 then
    begin
      inc(x);
      b[x]:=2000+i;
    end;
  end;
  writeln(x);
  for i:=1 to x-1 do write(b[i],' ');
  if x > 0 then writeln(b[x]);
  close(input);
  close(output);
end.
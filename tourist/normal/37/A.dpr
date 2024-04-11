{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,k1,k2: longint;
  a,b: array [0..10010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
  begin
    read(a[i]);
    inc(b[a[i]]);
  end;
  k1:=0; k2:=0;
  for i:=1 to 1000 do
  begin
    if b[i] > k1 then k1:=b[i];
    if b[i] > 0 then inc(k2);
  end;
  writeln(k1,' ',k2);
  close(input);
  close(output);
end.
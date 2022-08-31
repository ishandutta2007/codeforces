{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,i,j,x,y: longint;
  a: array [0..110] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for i:=1 to n do a[i]:=0;
  for i:=1 to m do
  begin
    read(x,y);
    for j:=x to y do inc(a[j]);
  end;
  for i:=1 to n do
    if a[i] <> 1 then
    begin
      writeln(i,' ',a[i]);
      halt;
    end;
  writeln('OK');
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,tmp,c,f: longint;
  first: boolean;
  a: array [0..1010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i] > a[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      end;
  if n = 1 then writeln(a[1]) else
  begin
    c:=0; f:=0;
    for i:=1 to n do
      if a[i] < 0 then
      begin
        inc(c);
        f:=i;
      end;
    if c and 1 = 0 then f:=0;
    first:=True;
    for i:=1 to n do
      if (i <> f) and (a[i] <> 0) then
      begin
        if not first then write(' ');
        first:=False;
        write(a[i]);
      end;
    if first then write(0);
    writeln;
  end;
  close(input);
  close(output);
end.
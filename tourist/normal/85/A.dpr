{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  if n = 1 then
  begin
    writeln('a');
    writeln('a');
    writeln('b');
    writeln('b');
  end else
  if n = 2 then
  begin
    writeln('aa');
    writeln('bb');
    writeln('cc');
    writeln('dd');
  end else
  if n and 1 = 1 then
  begin
    for i:=1 to n do
      if i = 1 then write('e') else
      if i mod 4 > 1 then write('b')
      else write('a');
    writeln;
    for i:=1 to n do
      if i = 1 then write('e') else
      if i mod 4 > 1 then write('c')
      else write('d');
    writeln;
    for i:=1 to n do
      if i = n then write('f') else
      if (i mod 4 = 1) or (i mod 4 = 2) then write('b')
      else write('a');
    writeln;
    for i:=1 to n do
      if i = n then write('f') else
      if (i mod 4 = 1) or (i mod 4 = 2) then write('c')
      else write('d');
    writeln;
  end else
  begin
    for i:=1 to n do
      if i = 1 then write('e') else
      if i = n then write('f') else
      if i mod 4 > 1 then write('b')
      else write('a');
    writeln;
    for i:=1 to n do
      if i = 1 then write('e') else
      if i = n then write('f') else
      if i mod 4 > 1 then write('c')
      else write('d');
    writeln;
    for i:=1 to n do
      if (i mod 4 = 1) or (i mod 4 = 2) then write('b')
      else write('a');
    writeln;
    for i:=1 to n do
      if (i mod 4 = 1) or (i mod 4 = 2) then write('c')
      else write('d');
    writeln;
  end;
  close(input);
  close(output);
end.
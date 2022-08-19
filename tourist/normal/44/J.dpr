{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  b: array [0..1010,0..1010] of longint;
  a: array [0..1010,0..1010] of char;
  n,m,i,j,kc: longint;
  ch: char;

procedure wr;
begin
  writeln('NO');
  halt;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  fillchar(a,sizeof(a),'.');
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(ch);
      while not (ch in ['.','w','b']) do read(ch);
      a[i,j]:=ch;
    end;
  fillchar(b,sizeof(b),0);
  kc:=0;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] = 'b' then wr else
      if a[i,j] = 'w' then
        if (a[i,j+1] = 'b') and (a[i,j+2] = 'w') then
        begin
          a[i,j]:='.'; a[i,j+1]:='.'; a[i,j+2]:='.';
          inc(kc);
          b[i,j]:=kc; b[i,j+1]:=kc; b[i,j+2]:=kc;
        end else
        if (a[i+1,j] = 'b') and (a[i+2,j] = 'w') then
        begin
          a[i,j]:='.'; a[i+1,j]:='.'; a[i+2,j]:='.';
          inc(kc);
          b[i,j]:=kc; b[i+1,j]:=kc; b[i+2,j]:=kc;
        end
        else wr;
  writeln('YES');
  for i:=1 to n do
    for j:=1 to m do
      if b[i,j] > 0 then
        if b[i+1,j] = b[i,j] then
        begin
          if j and 1 = 1 then b[i,j]:=-1
          else b[i,j]:=-2;
          b[i+1,j]:=b[i,j];
          b[i+2,j]:=b[i,j];
        end else
        begin
          if i and 1 = 1 then b[i,j]:=-3
          else b[i,j]:=-4;
          b[i,j+1]:=b[i,j];
          b[i,j+2]:=b[i,j];
        end;
  for i:=1 to n do
  begin
    for j:=1 to m do
      if b[i,j] = 0 then write('.')
      else write(Chr(96-b[i,j]));
    writeln;
  end;
  close(input);
  close(output);
end.
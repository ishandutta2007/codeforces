{$R-,S-,Q-,I-,O+}
var
  n,i,j,x: longint;
  a,c: array [0..4444444] of longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  fillchar(c,sizeof(c),0);
  for i:=1 to n do c[a[i]]:=a[i];
  for i:=0 to 1 shl 22-1 do
    if c[i] = 0 then
      for j:=0 to 21 do
        if i and (1 shl j) <> 0 then
          if c[i-(1 shl j)] > 0 then
          begin
            c[i]:=c[i-(1 shl j)];
            break;
          end;
  for i:=1 to n do
  begin
    x:=c[1 shl 22-1-a[i]];
    if x = 0 then x:=-1;
    write(x);
    if i < n then write(' ');
  end;
  writeln;
end.
uses math;
var
  n,i,j,k:longint;
  ch:char;
  f:array[1..1111,0..1]of longint;
  a:array[1..1111]of longint;
begin
  readln(n);
  for i:=1 to n do begin
    read(ch);a[i]:=ord(ch)-48;
  end;
  fillchar(f,sizeof(f),$F);
  for i:=0 to 1 do f[1][i]:=ord(a[1]<>i);
  for i:=2 to n do
    for j:=0 to 1 do
      for k:=0 to 1 do
        if (j<>k)then
          f[i][k]:=min(f[i][k],f[i-1][j]+ord(k<>a[i]));
  writeln(min(f[n][0],f[n][1]));
end.
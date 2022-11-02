var
  a:array[0..1111,0..1111]of longint;
  n,i,j,m:longint;

begin
  read(n);
  if (n=4)then begin
    writeln(-1);
    exit;
  end;
  if (n and 1=1)then begin
    fillchar(a,sizeof(a),$0);
    a[1][2]:=1;a[2][3]:=1;a[3][1]:=1;
    m:=3;
  end else begin
    a[1][2]:=1;a[1][3]:=1;a[1][4]:=1;
    a[2][3]:=1;a[2][4]:=1;a[2][5]:=1;
    a[3][4]:=1;a[3][6]:=1;
    a[4][5]:=1;a[4][6]:=1;
    a[5][1]:=1;a[5][3]:=1;a[5][6]:=1;
    a[6][1]:=1;a[6][2]:=1;
    m:=6;
  end;
  while (m<n)do begin
    a[m+1][m+2]:=1;
    for i:=1 to m do a[i][m+1]:=1;
    for i:=1 to m do a[m+2][i]:=1;
    inc(m,2);
  end;
  for i:=1 to n do begin
    for j:=1 to n do write(a[i][j],' ');
    writeln;
  end;
end.
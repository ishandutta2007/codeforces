var
  a:array[1..3,1..3]of longint;
  sum,i,j,ct:longint;

begin
  for i:=1 to 3 do for j:=1 to 3 do read(a[i][j]);
  for ct:=1 to 100000 do begin
    a[1][1]:=ct;
    sum:=a[1][1]+a[1][2]+a[1][3];
    a[2][2]:=sum-(a[1][2]+a[3][2]);
    a[3][3]:=sum-(a[1][3]+a[2][3]);
    if (a[1][1]+a[1][2]+a[1][3]<>a[2][1]+a[2][2]+a[2][3])then continue;
    if (a[1][1]+a[1][2]+a[1][3]<>a[3][1]+a[3][2]+a[3][3])then continue;
    if (a[1][1]+a[1][2]+a[1][3]<>a[1][1]+a[2][2]+a[3][3])then continue;
    if (a[1][1]+a[1][2]+a[1][3]<>a[1][3]+a[2][2]+a[3][1])then continue;
    if (a[1][1]+a[1][2]+a[1][3]<>a[1][1]+a[2][1]+a[3][1])then continue;
    if (a[1][1]+a[1][2]+a[1][3]<>a[1][2]+a[2][2]+a[3][2])then continue;
    if (a[1][1]+a[1][2]+a[1][3]<>a[1][3]+a[2][3]+a[3][3])then continue;
    for i:=1 to 3 do begin
      for j:=1 to 3 do write(a[i][j],' ');
      writeln;
    end;
  end;
end.
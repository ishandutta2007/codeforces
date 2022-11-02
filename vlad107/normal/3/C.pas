var
  i,j,k1,k2:longint;
  a:array[1..3,1..3]of char;
  first,second:boolean;
begin
  for i:=1 to 3 do begin
    for j:=1 to 3 do read(a[i][j]);
    readln;
  end;
  k1:=0;k2:=0;
  for i:=1 to 3 do for j:=1 to 3 do 
    if (a[i][j]='X')then inc(k1)else
    if (a[i][j]='0')then inc(k2);
  if (k1-k2<0)or(k1-k2>1)then begin
    writeln('illegal');
    exit;
  end;
  first:=false;
  second:=false;
  if (a[1][1]<>'.')and(a[1][1]=a[1][2])and(a[1][1]=a[1][3])then begin
    if (a[1][1]='X')then first:=true else
    second:=true;
  end;
  if (a[2][1]<>'.')and(a[2][1]=a[2][2])and(a[2][1]=a[2][3])then begin
    if (a[2][1]='X')then first:=true else
    second:=true;
  end;
  if (a[3][1]<>'.')and(a[3][1]=a[3][2])and(a[3][1]=a[3][3])then begin
    if (a[3][1]='X')then first:=true else
    second:=true;
  end;
  if (a[1][1]<>'.')and(a[1][1]=a[2][1])and(a[1][1]=a[3][1])then begin
    if (a[1][1]='X')then first:=true else
    second:=true;
  end;
  if (a[1][2]<>'.')and(a[1][2]=a[2][2])and(a[1][2]=a[3][2])then begin
    if (a[1][2]='X')then first:=true else
    second:=true;
  end;
  if (a[1][3]<>'.')and(a[1][3]=a[2][3])and(a[1][3]=a[3][3])then begin
    if (a[1][3]='X')then first:=true else
    second:=true;
  end;
  if (a[1][1]<>'.')and(a[1][1]=a[2][2])and(a[1][1]=a[3][3])then begin
    if (a[1][1]='X')then first:=true else
    second:=true;
  end;
  if (a[1][3]<>'.')and(a[1][3]=a[2][2])and(a[1][3]=a[3][1])then begin
    if (a[1][3]='X')then first:=true else
    second:=true;
  end;
  if (first)or(second)then begin
    if (first)and(k1-k2=0)then writeln('illegal')else
    if (second)and(k1-k2=1)then writeln('illegal')else
    if (first)and(second)then writeln('illegal')else
    if (first)then writeln('the first player won')else
    if (second)then writeln('the second player won');
    exit;
  end;
  if (k1+k2=9)then begin
    writeln('draw');
    exit;
  end;
  if (k1-k2=0)
    then writeln('first')
    else writeln('second');
end.
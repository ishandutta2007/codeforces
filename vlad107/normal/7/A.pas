var
  q,res,i,j:longint;
  black:boolean;
  a:array[1..1000,1..1000]of char;
begin
  black:=true;
  for i:=1 to 8 do begin
    for j:=1 to 8 do begin
      read(a[i][j]);
      if (a[i][j]='W')then black:=false;
    end;
    readln;
  end;
  if (black)then begin
    writeln(8);exit;
  end;
  res:=0;
  for i:=1 to 8 do begin
    q:=0;
    for j:=1 to 8 do 
      if (a[i][j]='B')then inc(q);
    if (q=8)then inc(res);
    q:=0;
    for j:=1 to 8 do 
      if (a[j][i]='B')then inc(q);
    if (q=8)then inc(res);
  end;
  writeln(res);
end.
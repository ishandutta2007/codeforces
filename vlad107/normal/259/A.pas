var
  i,j,pj:longint;
  a:array[0..555,0..555]of char;

begin
  for i:=1 to 8 do begin
    for j:=1 to 8 do read(a[i][j]);
    readln;
  end;
  for i:=1 to 8 do
    for j:=1 to 8 do begin
      pj:=j-1;
      if (pj=0)then pj:=8;
      if (a[i][j]=a[i][pj])then begin
        writeln('NO');
        exit;
      end;
    end;
  writeln('YES');
end.
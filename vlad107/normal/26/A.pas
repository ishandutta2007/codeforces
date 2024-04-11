var
  res,kol,n,i,j:longint;
  f:array[1..100000]of boolean;
begin
  read(n);
  fillchar(f,sizeof(f),true);
  f[1]:=false;
  for i:=2 to n do 
    if (f[i])then 
      for j:=2 to n div i do 
        f[i*j]:=false;
  res:=0;
  for i:=1 to n do begin
    kol:=0;
    for j:=2 to n-1 do 
      if (i mod j=0)and(f[j])then inc(kol);
    if (kol=2)then inc(res);
  end;
  writeln(res);
end.
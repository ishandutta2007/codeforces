var
  n,i,j,m,x,k1:longint;
  g:array[0..44444,0..222]of boolean;
  kg,w:array[0..44444]of longint;
  r:array[0..222]of boolean;

begin
  read(n);
  if (n=2)then begin
    read(kg[1]);
    read(x);
    writeln('1 ',x);
    write(kg[1]-1);
    for j:=1 to kg[1]-1 do begin
      read(x);
      write(' ',x);
    end;
    writeln;
    exit;
  end;
  fillchar(g,sizeof(g),false);
  m:=n*(n-1)shr 1;
  for i:=1 to m do begin
    read(kg[i]);
    for j:=1 to kg[i]do begin
      read(x);
      g[i][x]:=true;
    end;
  end;
  x:=1;
  fillchar(r,sizeof(r),false);
  fillchar(w,sizeof(w),false);
  while (not g[1][x])do inc(x);
  for i:=2 to m do
    if (g[i][x])then begin
      for j:=1 to 200 do
        if (g[1][j])then inc(w[j]);
      for j:=1 to 200 do
        if (g[i][j])then inc(w[j]);
      k1:=0;
      for j:=1 to 200 do
        if (w[j]=2)then inc(k1);
      write(k1);
      for j:=1 to 200 do
        if (w[j]=2)then begin
          r[j]:=true;
          write(' ',j);
        end;
      writeln;
      break;
    end;
  for i:=1 to m do
    if (g[i][x])then begin
      k1:=0;
      for j:=1 to 200 do
        if (not r[j])and(g[i][j])then inc(k1);
      write(k1);
      for j:=1 to 200 do
        if (not r[j])and(g[i][j])then write(' ',j);
      writeln;
    end;
end.
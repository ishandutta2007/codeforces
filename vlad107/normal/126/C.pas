var
  res,n,i,j:longint;
  hx,hy:array[0..500500]of longint;
  a:array[0..2222,0..2222]of longint;
  ch:char;

begin
  readln(n);
  for i:=1 to n do begin
    for j:=1 to n do begin
      read(ch);
      a[i][j]:=ord(ch)-48;
    end;
    readln;
  end;
  res:=0;
  fillchar(hx,sizeof(hx),$0);
  fillchar(hy,sizeof(hy),$0);
  for i:=1 to n do begin
    for j:=n downto i+1 do begin
      if (a[i][j] xor hx[i] xor hy[j]=1)then begin
        hx[i]:=hx[i] xor 1;
        hy[j]:=hy[j] xor 1;
        inc(res);
      end;
    end;
    a[i][i]:=a[i][i] xor hx[i] xor hy[i];
  end;
  fillchar(hx,sizeof(hx),$0);
  fillchar(hy,sizeof(hy),$0);
  for i:=n downto 1 do begin
    for j:=1 to i-1 do
      if (a[i][j] xor hx[i] xor hy[j]=1)then begin
        hx[i]:=hx[i] xor 1;
        hy[j]:=hy[j] xor 1;
        inc(res);
      end;
    if (a[i][i] xor hx[i] xor hy[i]=1)then inc(res);
  end;
  writeln(res);
end.
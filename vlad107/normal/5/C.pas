var
  k,res,kol,i,j:longint;
  s:ansistring;
  f:array[0..1000500]of longint;
begin
  readln(s);
  j:=1;k:=0;res:=0;
  fillchar((f),sizeof(f),$0);
  for i:=1 to length(s)do begin
    if (s[i]='(')then inc(k)else dec(k);
    while (k<0)do begin
      if (s[j]='(')then dec(k)else inc(k);
      inc(j);
    end;
    if (k=0)and(i-j+1>res)then begin
      res:=i-j+1;
      f[j]:=i;
      kol:=1;
    end else
    if (k=0)and(i-j+1=res)then begin
      inc(kol);
      f[j]:=i;
    end;
  end;
  j:=length(s);k:=0;
  for i:=length(s)downto 1 do begin
    if (s[i]=')')then inc(k)else dec(k);
    while (k<0)do begin
      if (s[j]=')')then dec(k)else inc(k);
      dec(j);
    end;
    if (k=0)and(j-i+1>res)then begin
      res:=j-i+1;
      kol:=1;
    end else
    if (k=0)and(j-i+1=res)and(f[i]<>j)then inc(kol);
  end;
  if (res=0)then kol:=1;
  writeln(res,' ',kol);
end.
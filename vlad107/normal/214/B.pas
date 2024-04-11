{$r-,q-,s-,i-,o+}
var 
  kt,n,x,i,j,sum,k:longint;
  kol:array[0..10]of longint;

begin
  read(n);
  sum:=0;
  fillchar(kol,sizeof(kol),$0);
  for i:=1 to n do begin
    read(x);
    inc(kol[x]);
    sum:=sum+x;
  end;
  if (sum mod 3<>0)then begin
    for j:=1 to 9 do 
      if (sum mod 3=j mod 3)and(kol[j]>0)then begin
        dec(kol[j]);
        dec(sum,j);
        break;
      end;
    if (sum mod 3<>0)then begin
      for j:=1 to 9 do begin
        for k:=1 to 9 do 
          if (kol[j]>0)and(kol[k]>ord(k=j))and((j+k)mod 3=sum mod 3)then begin
            dec(sum,j+k);
            dec(kol[j]);
            dec(kol[k]);
            break;
          end;
        if (sum mod 3=0)then break;
      end;
    end;
    kt:=0;
    for i:=0 to 9 do inc(kt,kol[i]);
    if (sum mod 3<>0)or(kt=0)then begin
      writeln(-1);
      exit;
    end;
  end;
  if (kol[0]=0)then begin
    writeln(-1);
    exit;
  end;
  kt:=0;
  for i:=0 to 9 do inc(kt,kol[i]);
  if (kol[0]=kt)then kol[0]:=1;
  for i:=9 downto 0 do 
    for j:=1 to kol[i]do write(i);
  writeln;
end.
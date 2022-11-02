{$r-,q-,s-,i-,o+}
var
  g:array[0..11111,0..1111]of longint;
  kt,kq,n,i,j:longint;
  kg:array[0..11111]of longint;
  found:boolean;

begin
  read(n);
  found:=false;
  kt:=0;kq:=0;
  fillchar(kg,sizeof(kg),$0);
  i:=1;
  kq:=1;
  while (not found)do begin
    inc(i);
    for j:=1 to i-1 do begin
      inc(kt);
      if (kt>n)then begin
        found:=true;
        break;
      end;
      inc(kg[i]);g[i][kg[i]]:=kt;
      inc(kg[j]);g[j][kg[j]]:=kt;
    end;
    if (not found)then inc(kq);
  end;
  writeln(kq);
  for i:=1 to kq do begin
    for j:=1 to kg[i]do write(g[i][j],' ');
    writeln;
  end;
end.
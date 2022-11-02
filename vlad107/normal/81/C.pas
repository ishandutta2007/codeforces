var
  n,a,b,i:longint;
  t,kt,ka:array[0..100500]of longint;

begin
  read(n,a,b);
  fillchar(kt,sizeof(kt),$0);
  fillchar(ka,sizeof(ka),$0);
  for i:=1 to n do begin
    read(t[i]);
    inc(kt[t[i]]);
  end;
  if (a>b)then begin
    for i:=1 to 5 do 
      if (kt[i]>=a)then begin
        ka[i]:=a;
        a:=0;
      end else begin
        ka[i]:=kt[i];
        dec(a,kt[i]);
      end;
  end else if (a<b)then begin
    for i:=5 downto 1 do 
      if (kt[i]>=a)then begin
        ka[i]:=a;
        a:=0;
      end else begin
        ka[i]:=kt[i];
        dec(a,kt[i]);
      end;
  end else begin
    for i:=1 to a do write('1 ');
    for i:=1 to a do write('2 ');
    writeln;
    exit;
  end;
  for i:=1 to n do 
    if (ka[t[i]]>0)
      then begin
        write(1,' ');
        dec(ka[t[i]]);
      end else write(2,' ');
  writeln;
end.
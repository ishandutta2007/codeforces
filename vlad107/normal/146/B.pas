var
  x,a,b,c,bb,cc:longint;

begin
  read(a,b);
  if (b>a)then begin
    writeln(b);
    exit;
  end;
  for c:=a+1 to 1000000000 do begin
    bb:=b;
    cc:=c;
    while (cc>0)do begin
      x:=cc mod 10;
      cc:=cc div 10;
      if (x<>4)and(x<>7)then continue;
      if (x<>bb mod 10)then begin
        bb:=-1;
        break; 
      end;
      bb:=bb div 10;
    end;
    if (bb=0)then begin
      writeln(c);
      exit;
    end;
  end;
end.
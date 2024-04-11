var
  t,a,b,c,d,e,f:longint;
begin
  read(a,b,c,d,e,f);
  if (a*c=0)and(b*d>0)then begin
    writeln('Ron');
    exit;
  end;
  if (c=0)and(d>0)then begin
    writeln('Ron');
    exit;
  end;
  if (a*c*e=0)and(b*d*f>0)
    then writeln('Ron')
    else begin
      if (b*d*f=0)then begin
        writeln('Hermione');
        exit;
      end;
      t:=10000*b;
      t:=t div c;
      t:=t*d;
      t:=t div e;
      t:=t*f;
      if (t>a*10000)then begin
        writeln('Ron');
        exit;
      end;
      writeln('Hermione');
    end;
end.
var
  j,kt,n,m,k,p,i,xx,yy:longint;
  x,y:array[0..1111]of longint;
begin
  read(n,m,k,p);
  for i:=1 to k do read(x[i],y[i]);
  for i:=1 to p do begin
    read(xx,yy);
    kt:=m*(xx-1)+yy;
    for j:=1 to k do begin
      if (xx>x[j])or(xx=x[j])and(yy>y[j])then dec(kt);
      if (xx=x[j])and(yy=y[j])then begin
        kt:=-1;break;
      end;
    end;
    case (kt mod 3)of
      -1:writeln('Waste');
      0:writeln('Grapes');
      1:writeln('Carrots');
      2:writeln('Kiwis');
    end;
  end;
end.
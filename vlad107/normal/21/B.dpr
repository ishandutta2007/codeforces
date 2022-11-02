var
  a1, b1, c1, a2, b2, c2, dx, dy, d : longint;

begin
  readln(a1, b1, c1);
  readln(a2, b2, c2);
  if (a1=b1)and (a1=0)and (c1<>0)then begin
    writeln(0);exit;
  end;
  if (a2=b2)and (a2=0)and (c2<>0)then begin
    writeln(0);exit;
  end;
  d := a1*b2-b1*a2;
  dx := -b1*c2+c1*b2;
  dy := -c1*a2+a1*c2;
  if (d <> 0)
    then writeln(1)
    else
  if (dy = 0) and (dx = 0)
    then writeln(-1)
    else writeln(0);
end.
var
  kt,kq,n,i,x,j:longint;
  kol:array[0..500500]of longint;
  name:array[0..500500]of ansistring;
  s,p:ansistring;

begin
  readln(n);
  kt:=0;
  for i:=1 to n do begin
    readln(s);
    p:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    val(s,x);
    j:=1;
    while (j<=kt)and(name[j]<>p)do inc(j);
    if (j=kt+1)then begin
      name[j]:=p;
      kol[j]:=0;
      inc(kt);
    end;
    if (x>kol[j])then kol[j]:=x;
  end;
  writeln(kt);
  for i:=1 to kt do begin
    kq:=0;
    for j:=1 to kt do 
      if (kol[i]>=kol[j])then inc(kq);
    write(name[i],' ');
    if (100*kq>=99*kt)then writeln('pro')else
    if (100*kq>=90*kt)then writeln('hardcore')else
    if (100*kq>=80*kt)then writeln('average')else
    if (100*kq>=50*kt)then writeln('random')else
    writeln('noob');
  end;
end.
var
  res:char;
  abc:string;
  a:array[1..10] of string;
  kol,i,j,q:longint;

begin
  abc:='FMS';
  readln(a[1]);
  readln(a[2]);
  readln(a[3]);
  kol:=0;
  for i:=1 to 3 do begin
    q:=0;
    for j:=1 to 3 do 
      if (i<>j)then begin
        if (a[i][1]='r')and(a[j][1]='s')then inc(q)else
        if (a[i][1]='p')and(a[j][1]='r')then inc(q)else
        if (a[i][1]='s')and(a[j][1]='p')then inc(q);
      end;
    if (q=2)then begin
      inc(kol);
      res:=abc[i];
    end;
  end;
  if (kol<>1)
    then writeln('?')
    else writeln(res);
end.
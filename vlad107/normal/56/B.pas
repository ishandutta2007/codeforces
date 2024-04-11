var
  tmp,l,r,tr,tl,n,i:longint;
  a:array[1..100000]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  l:=0;r:=0;
  for i:=1 to n do begin
    if (a[i]=i)then continue;
    if (l=0)then l:=i;
    r:=i;
  end;
  if (l=0)then begin
    writeln('0 0');
    exit;
  end;
  tl:=l;tr:=r;
  while (l<r)do begin
    tmp:=a[l];a[l]:=a[r];a[r]:=tmp;
    inc(l);dec(r);
  end;
  for i:=1 to n do 
    if (a[i]<>i)then begin
      tl:=0;tr:=0;
      break;
    end;
  writeln(tl,' ',tr);
end.
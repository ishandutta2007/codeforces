var
  sum,n,i,x,y:longint;
  a:array[0..1111]of longint;

begin
  read(n);
  sum:=0;
  for i:=1 to n do begin
    read(a[i]);
    sum:=sum+a[i];
  end;
  if (sum mod n<>0)then begin
    writeln('Unrecoverable configuration.');
    exit;
  end;
  sum:=sum div n;
  x:=-1;y:=-1;
  for i:=1 to n do begin
    if (a[i]=sum)then continue;
    if (x=-1)then x:=i else
    if (y=-1)then y:=i else begin
      writeln('Unrecoverable configuration.');
      exit;
    end;
  end;
  if (x=-1)
    then writeln('Exemplary pages.')
    else begin
      if (a[x]>a[y])then begin
        i:=x;x:=y;y:=i;
      end;
      writeln((a[y]-a[x])div 2,' ml. from cup #',x,' to cup #',y,'.');
    end;
end.
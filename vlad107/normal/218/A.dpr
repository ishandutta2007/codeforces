var 
  n,k,i:longint;
  a:array[0..500500]of longint;

begin
  read(n,k);
  for i:=1 to 2*n+1 do read(a[i]);
  for i:=1 to n do begin
    if (k=0)then break;
    if (a[2*i]-1>a[2*i-1])and(a[2*i]-1>a[2*i+1])
      then begin
        dec(a[2*i]);
        dec(k);
      end;
  end;
  for i:=1 to 2*n+1 do write(a[i],' ');
end.
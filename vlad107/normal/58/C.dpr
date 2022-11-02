var
  y,q,res,n,x,i,min:longint;
  k,a:array[0..1000000]of longint;

begin
  read(n);
  fillchar(k,sizeof(k),$0);
  for i:=1 to 100000 do k[i]:=n;
  for i:=1 to n do begin
    read(x);
    a[i]:=x;
    if (i<=n shr 1)
      then begin
        if (x>=i)then dec(k[x-i+1]);
        continue;
      end;
    y:=x;
    q:=n-i+1;
    if (y>=q)then dec(k[y-q+1]);
  end;
  x:=0;
  min:=10000000;
  for i:=1 to 100000 do
    if (k[i]<min)then begin
      min:=k[i];
      x:=i;
    end;
  writeln(min);
end.
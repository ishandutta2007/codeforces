{$r-,q-,s-,i-,o+}
const
  inf=1000000000;

var
  a:array[0..500500]of int64;
  ans,min:int64;
  n,x,i:longint;

begin
  read(n,x);
  min:=inf;
  for i:=1 to n do begin
    read(a[i]);
    if (a[i]<min)then min:=a[i];
  end;
  for i:=1 to n do dec(a[i],min);
  ans:=int64(min)*n;
  i:=x;
  while (a[i]<>0)do begin
    ans:=ans+1;
    dec(a[i]);
    dec(i);
    if (i=0)then i:=n;
  end;
  a[i]:=ans;
  for i:=1 to n do write(a[i],' ');
  writeln;
end.
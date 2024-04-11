var
  a,b,n,m,na,nb:longint;

begin
  read(n,m,a,b);
  na:=((a-1)div m)+1;
  nb:=((b-1)div m)+1;
  if (m=1)or(na=nb)or((a mod m=1)and(b mod m=0))or((a mod m=1)and(b=n))then writeln(1)else
  if (nb=na+1)or(a mod m=1)or(b mod m=0)or(a mod m=(b+1) mod m)or(b=n)then writeln(2)else
  writeln(3);
end.
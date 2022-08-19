var n,k,s,i,p,k0,k1:integer;
x:real;
a:array [1..5000] of integer;

begin
readln(n);
k:=0;
s:=0;
for i:=1 to 2*n do
  begin
  read(x);
  a[i]:=round(1000*(x-trunc(x)));
  s+=a[i];
  if a[i]=0 then k+=1;
  end;
p:=1000*(n-k);
k0:=k;
while (p<s) and (k>0) do
  begin
  p+=1000;
  k-=1;
  end;
k1:=k;
k:=abs(p-s);
if (abs(p-1000-s)<k) and (k1<k0) then k:=abs(p-1000-s);
x:=k/1000;
writeln(x:10:3);
end.
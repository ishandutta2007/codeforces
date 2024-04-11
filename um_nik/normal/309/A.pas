var l,t,k,i,j:integer;
a:array [1..5000000] of integer;
b:array [1..1000100] of int64;
ans,p,n:int64;
s:real;


begin
readln(n,l,t);
t*=2;
p:=t div l;
t:=t mod l;
for i:=1 to n do read(a[i]);
for i:=1 to n do
  begin
  for j:=1 to 3 do
    begin
    a[i+j*n]:=a[i]+j*l;
    end;
  end;
j:=1;
for i:=1 to n do
  begin
  while a[j]-a[i]<=t do j+=1;
  b[i]:=j-i-1;
  end;
ans:=0;
for i:=1 to n do ans+=b[i];
s:=p;
s*=n*(n-1);
s+=ans;
writeln((s/4):25:7);
end.
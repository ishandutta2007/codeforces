var n,i,j,k,m,f,p,r:integer;
s:string;
a:array [0..1000100] of integer;

begin
readln(s);
n:=length(s);
k:=1;
a[1]:=1;
for i:=2 to n do
  begin
  if s[i]=s[i-1] then a[k]+=1 else
    begin
    k+=1;
    a[k]:=1;
    end;
  end;
if k mod 2 =1 then
  begin
  a[1]+=a[k];
  k-=1;
  end;
a[k+1]:=0;
m:=0;
for i:=1 to k do
  if a[i]>1 then m+=1;
f:=1;
while a[f]=1 do f+=1;
f-=1;
a[0]:=0;
p:=k;
while a[p]=1 do p-=1;
p:=k-p;
r:=0;
for i:=f+1 to k-p do
  begin
  if a[i]=1 then
    begin
    r+=1;
    end else
    begin
    if r>0 then
      begin
      m+=r div 2;
      r:=0;
      end;
    end;
  end;
if f<k then m+=(p+f) div 2 else m:=f div 2;
writeln(m);
end.
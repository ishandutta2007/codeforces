var n,i:integer;
a,b:array [1..100000] of integer;
d,c:array [0..100000] of real;
ans:real;

procedure qsort(x,y:integer);
var i,j,z:integer;
o,m:real;
  begin
  if x<y then
    begin
    i:=x;
    j:=y;
    m:=c[(i+j) div 2];
    while i<=j do
      begin
      while c[i]>m do i+=1;
      while c[j]<m do j-=1;
      if i<=j then
        begin
        z:=a[i];
        a[i]:=a[j];
        a[j]:=z;
        z:=b[i];
        b[i]:=b[j];
        b[j]:=z;
        o:=c[i];
        c[i]:=c[j];
        c[j]:=o;
        i+=1;
        j-=1;
        end;
      end;
    qsort(i,y);
    qsort(x,j);
    end;
  end;

begin
readln(n);
for i:=1 to n do
  begin
  readln(a[i],b[i]);
  if b[i]=100 then c[i]:=1000000 else c[i]:=(a[i]*b[i])/(100-b[i]);
  end;
qsort(1,n);
// for i:=1 to n do writeln(a[i],' ',b[i]);
d[0]:=0;
for i:=1 to n do d[i]:=d[i-1]+(1-b[i]/100);
ans:=0;
for i:=1 to n do
  begin
  ans+=a[i]*(1+b[i]*(d[n]-d[i])/100)
  end;
writeln(ans:20:10);
end.
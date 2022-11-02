{$r-,q-,s-,i-,o+}
var
  cr,r2:extended;
  x,y,r1,i,j,p1,p2,n,m,k:longint;
  a,b,c:array[0..500500]of longint;

begin
  read(k);
  r1:=0;
  for i:=1 to k do begin
    read(c[i]);
    if (c[i]>r1)then r1:=c[i];
  end;
  read(n);
  for i:=1 to n do read(a[i]);
  read(m);
  for i:=1 to m do read(b[i]);
  read(x,y);
  r2:=0;
  for i:=1 to n do 
    for j:=1 to m do begin
      p1:=a[i];p2:=b[j];
      cr:=p1/(x*p2+y*p1);
      if (cr>r2)then r2:=cr;
    end;
  r2:=sqrt(r2*y)*r1;
  writeln(r2:0:10);
end.
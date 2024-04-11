const
  inf=1000000000;

var
  m1,m2,n1,n2,m,tmp,a1,a2,n,i,j:longint;
  c,a,b:array[0..500500]of longint;

begin
  read(m,n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (a[j]<a[j+1])then begin
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
      end;
  a1:=0;a2:=0;
  fillchar(b,sizeof(b),$0);
  fillchar(c,sizeof(c),$0);
  for i:=1 to m do begin
    n1:=0;n2:=0;
    m1:=0;m2:=inf;
    for j:=1 to n do begin
      if (a[j]-b[j]>m1)then begin
        m1:=a[j]-b[j];
        n1:=j;
      end;
      if (a[j]-c[j]<>0)and(a[j]-c[j]<m2)then begin
        m2:=a[j]-c[j];
        n2:=j;
      end;
    end;
    inc(a1,m1);
    inc(a2,m2);
    inc(b[n1]);
    inc(c[n2]);
  end;
  writeln(a1,' ',a2);
end.
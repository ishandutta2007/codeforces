var
  n,i,j:longint;
  a,b:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do begin
    read(a[i]);
    inc(b[i mod 3],a[i]);
  end;
  j:=0;
  for i:=1 to 2 do
    if (b[i]>b[j])then j:=i;
  if (j=0)then writeln('back')else
  if (j=1)then writeln('chest')else
  if (j=2)then writeln('biceps');
end.
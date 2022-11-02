{$r-,q-,s-,i-,o+}
var
  z:array[0..5000000]of longint;
  s,p,t:ansistring;
  i,q,maxq:longint;

begin
  readln(s);
  p:=s;
  delete(p,1,1);
  delete(p,length(p),1);
  t:=s+'#'+p;
  z[1]:=0;q:=0;
  maxq:=0;
  for i:=2 to length(t)do begin
    while (q>0)and(t[q+1]<>t[i])do q:=z[q];
    if (t[q+1]=t[i])then inc(q);
    if (i>length(s)+1)and(q>maxq)then maxq:=q;
    z[i]:=q;
  end;
  i:=length(s);
  while (z[i]>maxq)do i:=z[i];
  if (z[i]=0)then writeln('Just a legend')else writeln(copy(s,1,z[i]));
end.
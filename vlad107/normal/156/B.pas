var
  kol,a:array[-500500..500500]of longint;
  killer:array[-500500..500500]of boolean;
  q,k0,k1,i,n,m,kt:longint;

begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do inc(kol[a[i]]);
  for i:=1 to n do 
    if (a[i]<0)then inc(k0)else inc(k1);
  kt:=0;    
  for i:=1 to n do begin
    q:=kol[i]+k0-kol[-i];
    killer[i]:=q=m;
    inc(kt,ord(killer[i]));
  end;
  for i:=1 to n do begin
    if (a[i]>0)and(not killer[a[i]])then writeln('Lie')else
    if (a[i]<0)and(not killer[-a[i]])then writeln('Truth')else
    if (kt>1)then writeln('Not defined')else
    if (a[i]>0)then writeln('Truth')else
    writeln('Lie');
  end;
end.
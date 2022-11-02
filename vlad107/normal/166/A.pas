var
  j,k,n,ans,i,tmp:longint;
  p,t,nom:array[0..500500]of longint;

begin
  read(n,k);
  for i:=1 to n do read(p[i],t[i]);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (p[j]<p[j+1])or(p[j]=p[j+1])and(t[j]>t[j+1])then begin
        tmp:=p[j];p[j]:=p[j+1];p[j+1]:=tmp;
        tmp:=t[j];t[j]:=t[j+1];t[j+1]:=tmp;
      end;
  nom[1]:=1;
  for i:=2 to n do 
    if (p[i]=p[i-1])and(t[i]=t[i-1])then nom[i]:=nom[i-1]else nom[i]:=i;
  nom[n+1]:=n+1;
  i:=1;
  while (k>=nom[i])do inc(i);
  dec(i);
  k:=nom[i];
  ans:=0;
  for i:=1 to n do
    if (nom[i]=k)then inc(ans);
  writeln(ans);      
end.
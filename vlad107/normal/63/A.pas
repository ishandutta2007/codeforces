var
  tmp,n,i,j:longint;
  k,nom:array[0..1000]of longint;
  a:array[0..10000]of string;
  ts,s:string;

begin
  readln(n);
  for i:=1 to n do begin
    readln(s);
    a[i]:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    if (s='rat')then k[i]:=0 else
    if (s='woman')then k[i]:=1 else
    if (s='child')then k[i]:=1 else
    if (s='man')then k[i]:=2 else
    k[i]:=3;
    nom[i]:=i;
  end;
  for i:=1 to n do 
    for j:=i+1 to n do 
      if (k[j]<k[i])or(k[j]=k[i])and(nom[j]<nom[i])then begin
        ts:=a[i];a[i]:=a[j];a[j]:=ts;
        tmp:=k[i];k[i]:=k[j];k[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
      end;
  for i:=1 to n do writeln(a[i]);
end.
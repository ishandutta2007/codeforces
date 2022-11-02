var
  st:array[1..10] of string;
  s:string;
  a:array[1..100] of longint;
  nom,min,x,j,n,i:longint;

begin
  st[1]:='S';
  st[2]:='M';
  st[3]:='L';
  st[4]:='XL';
  st[5]:='XXL';
  for i:=1 to 5 do read(a[i]);
  readln(n);
  for i:=1 to n do begin
    readln(s);
    if (s='S')then x:=1 else
    if (s='M')then x:=2 else 
    if (s='L')then x:=3 else
    if (s='XL')then x:=4 else
    if (s='XXL')then x:=5;
    min:=10000;
    for j:=1 to 5 do 
      if (a[j]>0) and (abs(j-x)<=min) then begin
        min:=abs(j-x);
        nom:=j;
      end;
    writeln(st[nom]);
    dec(a[nom]);
  end;
end.
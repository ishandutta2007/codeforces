{$r-,q-,s-,i-,o+}
var
  q,tmp,n,m,i,j,pi,ni:longint;
  r,nom,a:array[0..100500]of longint;

begin
  read(n,m);
  for i:=1 to m do read(a[i]);
  for i:=1 to m do nom[i]:=i;
  fillchar(r,sizeof(r),$FF);
  for i:=1 to n do begin
    pi:=i-1;
    if (pi<1)then pi:=n;
    ni:=i+1;
    if (ni>n)then ni:=1;
    for q:=1 to m-1 do 
      for j:=1 to m-1 do 
        if (a[j]<a[j+1])or(a[j]=a[j+1])and(nom[j+1]=r[1])then begin
          tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
          tmp:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp;
        end;
    for j:=1 to m do 
      if (a[j]>0)and(r[pi]<>nom[j])and(r[ni]<>nom[j])then begin
        r[i]:=nom[j];
        dec(a[j]);
        break;
      end;
    if (r[i]<0)then begin
      writeln(-1);
      exit;
    end;
  end;
  for i:=1 to n do write(r[i],' ');
  writeln;
end.
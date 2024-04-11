var
  a,kol,nom:array[0..500500]of longint;
  used:array[0..500500]of boolean;
  tmp,n,i,j,x:longint;
  s:ansistring;
  name:array[0..500500]of ansistring;

begin
  readln(n);
  for i:=1 to n do begin
    readln(s);
    name[i]:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    val(s,kol[i]);
    nom[i]:=i;
  end;
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (kol[nom[j]]>kol[nom[j+1]])then begin
        tmp:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp;
      end;
  fillchar(used,sizeof(used),false);
  for i:=1 to n do begin
    x:=kol[nom[i]];
    if (x>i-1)then begin
      writeln(-1);
      exit;
    end;
    for j:=1 to i-1 do 
	  if (a[j]>=i-x)then inc(a[j]);
	a[i]:=i-x;
  end;      
  for i:=1 to n do writeln(name[nom[i]],' ',a[i]);
end.
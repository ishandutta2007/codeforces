{$r-,q-,s-,i-,o+}
var
  nick,maxs,s:ansistring;
  x,j,i,n,kol,max:longint;

begin
  readln(n);
  max:=-maxlongint;
  for i:=1 to n do begin
    readln(s);
    nick:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    kol:=0;
    s:=s+' ';
    for j:=1 to 7 do begin
      val(copy(s,1,pos(' ',s)-1),x);
      delete(s,1,pos(' ',s));
      if (j>2)then inc(kol,x)else
      if (j=1)then inc(kol,x*100)else
      dec(kol,x*50);
    end;
    if (kol>max)then begin
      max:=kol;
      maxs:=nick;
    end;
  end;
  writeln(maxs);
end.
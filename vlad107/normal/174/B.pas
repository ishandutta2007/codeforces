var
  name,ext:array[0..500500]of ansistring;
  z,s:ansistring;
  kt,i,j,q:longint;

begin
  readln(s);
  i:=1;
  kt:=0;
  while (i<=length(s))do begin
    j:=i;
    while (i<=length(s))and(s[i]<>'.')do inc(i);
    if ((i-j>3)and(i>length(s)))or((i-j>8)and(j=1))or(i-j>11)then begin
      writeln('NO');
      exit;
    end;
    z:=copy(s,j,i-j);
    if (j=1)then begin
      inc(kt);
      name[kt]:=z;
    end else begin
      if (i>length(s))
        then q:=length(z)
        else 
      if (length(z)>9)
        then q:=length(z)-8
        else q:=1;
      ext[kt]:=copy(z,1,q);
      if (i<=length(s))then begin
        inc(kt);
        name[kt]:=copy(z,q+1,length(z));
      end;
    end;
    inc(i);
  end;
  for i:=1 to kt do 
    if (name[i]='')or(ext[i]='')then begin
      writeln('NO');
      exit;
    end;
  writeln('YES');
  for i:=1 to kt do writeln(name[i],'.',ext[i]);
end.
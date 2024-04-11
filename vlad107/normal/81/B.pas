{$r-,q-,s-,i-,o+}
var
  p,s:ansistring;
  i,l,r:longint;
begin
  readln(s); 
  i:=1;
  p:='';
  while (i<=length(s))do begin
    if (s[i]in['0'..'9'])then begin
      p:=p+s[i];
      inc(i);
      continue;
    end;
    if (s[i]='.')then begin
      if (length(p)=0)or(p[length(p)]=' ')
        then p:=p+'...'
        else p:=p+' ...';
      inc(i,3);
      continue;
    end;
    if (s[i]=',')then begin
      p:=p+', ';
      inc(i);
      continue;
    end;
    l:=i-1;
    r:=i+1;
    while (s[r]=' ')do inc(r);
    if (s[l]in['0'..'9'])and(s[r]in['0'..'9'])then begin
      p:=p+' ';
      i:=r;
      continue;
    end else inc(i);
  end;
  while (p[length(p)]=' ')do delete(p,length(p),1);
  writeln(p);
end.
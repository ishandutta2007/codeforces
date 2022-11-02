{$r-,q-,s-,i-,o+}
var
  s,p:ansistring;
  j,mf,i:longint;
  tf:array[0..500500,'a'..'z']of longint;
  f,g:array[0..500500]of longint;
  ch:char;

begin
  readln(s);
  readln(p);
  for ch:='a' to 'z' do tf[0][ch]:=0;
  for i:=1 to length(p)+1 do begin
    for ch:='a' to 'z' do begin
      tf[i][ch]:=tf[i-1][ch];
      if (i<=length(p))and(p[i]=ch)then tf[i][ch]:=i;
    end;
  end;
  mf:=0;
  for i:=1 to length(s)do begin
    f[i]:=tf[mf+1][s[i]];
    if (tf[mf+1][s[i]]=mf+1)then inc(mf);
  end;
  i:=1;j:=length(s);
  while (i<j)do begin
    ch:=s[i];s[i]:=s[j];s[j]:=ch;
    inc(i);dec(j);
  end;
  i:=1;j:=length(p);
  while (i<j)do begin
    ch:=p[i];p[i]:=p[j];p[j]:=ch;
    inc(i);dec(j);
  end;
  for ch:='a' to 'z' do tf[0][ch]:=0;
  for i:=1 to length(p)+1 do begin
    for ch:='a' to 'z' do begin
      tf[i][ch]:=tf[i-1][ch];
      if (i<=length(p))and(p[i]=ch)then tf[i][ch]:=i;
    end;
  end;
  mf:=0;
  for i:=1 to length(s)do begin
    g[length(s)-i+1]:=tf[mf+1][s[i]];
    if (tf[mf+1][s[i]]=mf+1)then inc(mf);
  end;
  for i:=1 to length(s)do 
    if (f[i]+g[i]-1<length(p))then begin
      writeln('No');
      exit;
    end;
  writeln('Yes');
end.
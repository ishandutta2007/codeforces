var
  i,ans:longint;
  s,p:ansistring;
  kch,pch:array['a'..'z']of longint;
  ch:char;

begin
  readln(s);
  readln(p);
  if (length(p)>length(s))then begin
    writeln(0);
    exit;
  end;
  fillchar(pch,sizeof(pch),$0);
  for i:=1 to length(p)do inc(pch[p[i]]);
  fillchar(kch,sizeof(kch),$0);
  for i:=1 to length(p)do inc(kch[s[i]]);
  ans:=0;
  for i:=length(p)to length(s)do begin
    inc(ans);
    for ch:='a' to 'z' do 
      if (kch[ch]>pch[ch])then begin
        dec(ans);
        break;
      end;
    if (i<length(s))then inc(kch[s[i+1]]);
    dec(kch[s[i-length(p)+1]]);
  end;
  writeln(ans);
end.
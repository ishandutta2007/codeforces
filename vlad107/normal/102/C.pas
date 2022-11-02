{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
var
  s:ansistring;
  min,i,k:longint;
  x,ch:char;
  kol:array['a'..'z']of longint;
  was:array['a'..'z']of boolean;


begin
  readln(s);
  fillchar(kol,sizeof(kol),$0);
  for i:=1 to length(s)do inc(kol[s[i]]);
  read(k);
  fillchar(was,sizeof(was),false);
  for ch:='a' to 'z' do
    if (kol[ch]=0)then was[ch]:=true;
  while (true)do begin
    min:=inf;
    for ch:='a' to 'z' do
      if (not was[ch])and(kol[ch]<min)then begin
        min:=kol[ch];
        x:=ch;
      end;
    if (min>k)then break;
    dec(k,min);
    was[x]:=true;
  end;
  k:=0;
  for ch:='a'to'z'do
    if (not was[ch])then inc(k);
  writeln(k);
  for i:=1 to length(s)do
    if (not was[s[i]])then write(s[i]);
  writeln;
end.
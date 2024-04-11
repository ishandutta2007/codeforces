var
  s,p:ansistring;
  i,j:longint;
  ch:char;
  kch:array['0'..'9']of longint;

begin
  readln(s);
  readln(p);
  fillchar(kch,sizeof(kch),$0);
  for i:=1 to length(p)do inc(kch[p[i]]);
  j:=1;
  for ch:='9' downto '1' do 
    for i:=1 to kch[ch] do begin
      while (j<=length(s))and(ch<=s[j])do inc(j);
      if (j<=length(s))then s[j]:=ch;
    end;
  writeln(s);
end.
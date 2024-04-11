{$r-,q-,s-,i-,o+}
var
  ch:char;
  s:ansistring;
  t:array['a'..'z']of char;
  k,kb,i,ct,q,j:longint;
  next:array[0..1500000,'a'..'z']of longint;

begin
  readln(s);
  for ch:='a' to 'z' do read(t[ch]);
  readln;
  readln(k);
  kb:=0;
  for i:=1 to length(s)do begin
    ct:=k;
    q:=0;
    for j:=i to length(s)do begin
      if (t[s[j]]='0')then dec(ct);
      if (ct<0)then break;
      if (next[q][s[j]]=0)then begin
        inc(kb);
        next[q][s[j]]:=kb;
      end;
      q:=next[q][s[j]];
    end;
  end; 
  writeln(kb);
end.
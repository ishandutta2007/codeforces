var
  s,p:ansistring;
  n,k,i,j:longint;

begin
  readln(n,k);
  readln(s);
  for i:=1 to k do begin
    p:=s;
    for j:=1 to length(s)-1 do
      if (s[j]='B')and(s[j+1]='G')then begin
        p[j]:='G';p[j+1]:='B';
      end;
    s:=p;
  end;
  writeln(s);
end.
{$r-,q-,s-,i-,o+}
var
  l1,l2,let:char;
  j,q,n,i:longint;
  s:string;
  a:array[0..111]of string;
  was:array[0..100500]of boolean;
  function downcase(c:char):Char;
    begin
      if (c in['A'..'Z'])
        then downcase:=chr(ord(c)+32)
        else downcase:=c;
    end;
  function minc(c:char):Char;
    begin
      if (upcase(c)='A')
        then minc:='B'
        else minc:='A';
    end;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  readln(s);
  fillchar(was,sizeof(was),false);
  for i:=1 to n do begin
    for j:=1 to length(s)-length(a[i])+1do begin
      q:=1;
      while (q<=length(a[i]))and(downcase(s[j+q-1])=downcase(a[i][q]))do inc(q);
      if (q>length(a[i]))then begin
        for q:=1 to length(a[i])do was[j+q-1]:=true;
      end;
    end;
  end;
  read(let);
  l1:=downcase(let);
  l2:=upcase(l1);
  for i:=1 to length(s)do
    if (not was[i])then write(s[i])else
    if (upcase(s[i])=l2)then begin
      if (s[i]in['a'..'z'])then write(downcase(minc(s[i]))) else write(upcase(minc(s[i])));
    end else 
    if (s[i]in['a'..'z'])then write(l1)
    else write(l2);
  writeln; 
end.
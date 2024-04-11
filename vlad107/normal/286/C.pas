var
  x,k,n,m,i:longint;
  s,a:array[0..1000000]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  read(m);
  for i:=1 to m do begin read(x);a[x]:=-a[x]; end;
  for i:=n downto 1 do 
    if (k=0)or(s[k]<>a[i])then begin
      inc(k);s[k]:=abs(a[i]);a[i]:=-s[k];
    end else dec(k);
  if (k<>0)then begin writeln('NO');exit; end;
  writeln('YES');
  for i:=1 to n do write(a[i],' ');
  writeln;
end.
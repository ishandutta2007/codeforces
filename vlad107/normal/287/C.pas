{$r-,q-,s-,i-,o+}
var
  n,i:longint;
  a:array[0..500500]of longint;

begin
  read(n);
  if (n=1)then begin
    writeln(1);
    exit;
  end;
  if (n mod 4=2)or(n mod 4=3)then begin
    writeln(-1);
    exit;
  end;
  i:=1;
  while (i<=n)do begin
    if (a[i]<>0)then begin inc(i);continue; end;
    if (i=n-i+1)then begin
      a[i]:=i;
      break;
    end;
    a[i]:=i+1;
    a[i+1]:=n-i+1;
    a[n-i+1]:=n-(i+1)+1;
    a[n-(i+1)+1]:=i;
  end; 
  for i:=1 to n do write(a[i],' ');   
  writeln;
end.
var
  i,n,h,j:longint;
  s:ansistring;
  a:array[0..1111]of string;

begin
  readln(s);
  i:=1;
  n:=0;
  while (i<=length(s))do begin
    inc(n);
    a[n]:='';
    while (s[i]<>'>')do begin
      a[n]:=a[n]+s[i];
      inc(i);
    end;
    a[n]:=a[n]+'>';
    inc(i);
  end;
  h:=0;
  for i:=1 to n do begin             
    if (pos('/',a[i])>0)then dec(h);
    for j:=1 to 2*h do write(' ');
    writeln(a[i]);
    if (pos('/',a[i])=0)then inc(h);
  end;
end.
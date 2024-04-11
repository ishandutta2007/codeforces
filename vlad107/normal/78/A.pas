var
  j,i,n,k:longint;
  s:string;

begin
  for i:=1 to 3 do begin
    readln(s);
    k:=0;
    for j:=1 to length(s)do
      if (s[j]in['a','e','i','o','u'])then inc(k);
    if ((i=1)or(i=3))and(k<>5)then begin
      writeln('NO');
      exit;
    end;
    if (i=2)and(k<>7)then begin
      writeln('NO');
      exit;
    end;
  end;
  writeln('YES');
end.
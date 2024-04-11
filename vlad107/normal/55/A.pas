var
  n,i,k:longint;
  was:array[0..10000]of boolean;
begin
  read(n);
  i:=1;
  fillchar(was,sizeof(was),false);
  k:=1;
  while (not was[i])do begin
    was[i]:=true;
    inc(i,k);
    if (i>n)then dec(i,n);
    inc(k);
  end;
  for i:=1 to n do 
    if (not was[i])then begin
      writeln('NO');
      exit;
    end;
  writeln('YES');
end.
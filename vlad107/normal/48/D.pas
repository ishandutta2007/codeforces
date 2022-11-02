var
  t,a:array[1..100100] of longint;
  i,n:longint;

begin
  read(n);
  for i:=1 to n do begin
     read(t[i]);
     inc(a[t[i]]);
  end;
  for i:=2 to 100000 do 
    if (a[i]>a[i-1])then begin
      writeln(-1);
      exit;
    end;
  writeln(a[1]);
  fillchar(a,sizeof(a),$0);
  for i:=1 to n do begin
    inc(a[t[i]]);
    write(a[t[i]], ' ');
  end;
  writeln;
end.
var
  n,i,k,x:longint;
  a:array[0..100500]of longint;

begin
  read(n);
  k:=0;
  for i:=1 to n do begin
    read(x);
    if (x=k+1)then begin
      inc(k);
      a[k]:=i;
    end;
  end;
  writeln(k);
  for i:=1 to k do write(2000+a[i],' ');
  writeln;
end.
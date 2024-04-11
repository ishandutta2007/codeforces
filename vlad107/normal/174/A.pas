var
  n,b,i:longint;
  a:array[0..500500]of longint;

begin
  read(n,b);
  for i:=1 to n do begin
    read(a[i]);
    b:=b+a[i];
  end;
  for i:=1 to n do
    if (b<a[i]*n)then begin
      writeln(-1);
      exit;
    end;
  for i:=1 to n do
    writeln((b/n-a[i]):0:10);
end.
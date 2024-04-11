var
  n,i,x:longint;
  a:array[0..5]of longint;

begin
  readln(n);
  for i:=1 to n do begin
    read(x);
    inc(a[x mod 3]);
  end;
  if (a[2]<a[1])then a[1]:=a[2];
  writeln((a[0]shr 1) + a[1]);
end.
var
  c,a,b:array[0..500500]of longint;
  k,s:int64;
  i,n:longint;

begin
  read(n);
  s:=0;
  for i:=1 to n do read(a[i]);
  s:=0;
  for i:=n downto 1 do begin
    if (a[i]-s>=0)then begin
      s:=a[i]-s;
      b[i]:=1;
      c[i+1]:=c[i+1] xor 1;
    end else begin
      b[i]:=0;
      s:=s-a[i];
    end;
  end;
  for i:=1 to n do c[i]:=c[i-1] xor c[i];
  for i:=1 to n do
    if (b[i] xor c[i]=0)then write('-')else write('+');
  writeln;
end.
var
  c1,c2:int64;
  m,n,i,x:longint;
  rev:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do begin
    read(x);
    rev[x]:=i;
  end;
  read(m);
  c1:=0;c2:=0;
  for i:=1 to m do begin
    read(x);
    c1:=c1+rev[x];
    c2:=c2+n-rev[x]+1;
  end;
  writeln(c1,' ',c2);
end.
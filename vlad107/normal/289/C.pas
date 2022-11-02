var
  m,n,k,i:longint;

begin
  readln(n,k);
  if (k>n)or((k=1)and(n>1))then begin
    writeln(-1);
    exit;
  end;
  if (k=1)and(n=1)then begin
    writeln('a');
    exit;
  end;
  m:=n-(k-2);
  for i:=1 to m do 
    if (i and 1=1)then write('a')else write('b');
  for i:=3 to k do write(chr(i+96));
  writeln;
end.
{$macro+}
{ $define free}

{$ifdef free}
uses math;
{$endif}

var
  n,k,i,ind:longint;
  a:array[1..100]of longint;

begin
  read(n,k);
  if k>1 then
    begin
      writeln('Yes');
      halt
    end;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]=0 then ind:=i
    end;
  read(a[ind]);
  for i:=1 to n-1 do
    if a[i]>a[i+1] then
      begin
        writeln('Yes');
        halt
      end;
  writeln('No')
end.
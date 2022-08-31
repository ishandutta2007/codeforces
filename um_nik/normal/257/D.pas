var n,i:integer;
s:int64;
a:array [1..100000] of int64;
b:array [1..100000] of integer;
begin
readln(n);
for i:=1 to n do
  begin
  read(a[i]);
  end;
s:=0;
for i:=n downto 1 do
  begin
  if s>0 then
    begin
    s:=s-a[i];
    b[i]:=0;
    end else
    begin
    s:=s+a[i];
    b[i]:=1;
    end;
  end;
for i:=1 to n do
  begin
  if s>=0 then
    begin
    if b[i]=0 then write('-') else write('+');
    end else
    begin
    if b[i]=1 then write('-') else write('+');
    end;
  end;
end.
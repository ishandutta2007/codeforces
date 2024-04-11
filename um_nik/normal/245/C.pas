var n,k,i,z,p:integer;
a:array [0..1000] of integer;
begin
readln(n);
for i:=0 to 300 do a[i]:=0;
for i:=1 to n do
read(a[i]);
if (n<3) or (n mod 2=0) then
  begin
  writeln(-1);
  end else
  begin
  k:=0;
  for i:=n downto 2 do
    begin
    if a[i]>0 then
      begin
      k:=k+a[i];
      z:=a[i];
      p:=i div 2;
      a[p]:=a[p]-z;
      a[p*2]:=a[p*2]-z;
      a[p*2+1]:=a[p*2+1]-z;
      end;
    end;
  if a[1]>0 then k:=k+a[1];
  writeln(k);
  end;
end.
var k,n,i,x,y,z:integer;
a,b,c:array [0..600] of integer;
begin
readln(n);
if n=1 then
  begin
  readln(x);
  if x=0 then writeln('BitAryo') else writeln('BitLGM');
  end;
if n=3 then
  begin
  readln(x,y,z);
  k:=(x xor y) xor z;
  if k=0 then writeln('BitAryo') else writeln('BitLGM');
  end;
if n=2 then
  begin
  readln(x,y);
  if x>y then
    begin
    z:=x;
    x:=y;
    y:=z;
    end;
  for i:=0 to 600 do a[i]:=0;
  k:=0;
  for i:=0 to 300 do
    begin
    if a[i]=0 then
      begin
      b[k]:=i;
      c[k]:=i+k;
      a[i]:=1;
      a[i+k]:=1;
      k+=1;
      end;
    end;
  k-=1;
  z:=0;
  for i:=0 to k do
    begin
    if (x=b[i]) and (y=c[i]) then
      begin
      z:=1;
      break;
      end;
    end;
  if z=0 then writeln('BitLGM') else writeln('BitAryo');
  end;
end.
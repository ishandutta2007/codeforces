var n,m,i,j,x,y:integer;
a:array [1..1000100] of integer;
b:array [0..20] of integer;


begin
readln(n,m);
b[0]:=1;
for i:=1 to 20 do b[i]:=2*b[i-1];
for i:=1 to b[n] do read(a[i+b[n]]);
for i:=b[n] downto 2 do
  begin
  j:=0;
  while b[j]<i do j+=1;
 // j-=1;
  if (n-j) mod 2=0 then a[i]:=a[2*i] or a[2*i-1] else a[i]:=a[2*i] xor a[2*i-1];
  end;
//for i:=2 to 8 do write(a[i], ' ');
for i:=1 to m do
  begin
  read(x,y);
  a[b[n]+x]:=y;
  x:=(b[n]+x+1) div 2;
  y:=1;
  while x>1 do
    begin
    if y mod 2=1 then
      begin
      a[x]:=a[2*x] or a[2*x-1];
      x:=(x+1) div 2;
      end else
      begin
      a[x]:=a[2*x] xor a[2*x-1];
      x:=(x+1) div 2;
      end;
    y+=1;
    end;
  //writeln(a[3]);
  writeln(a[2]);
  end;
end.
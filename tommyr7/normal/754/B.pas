var a:array[1..4,1..4]of char;
    i,j:longint;
	flag:boolean;
procedure deal(x,y,z:char);
var tot1,tot2:longint;
begin
  tot1:=0;
  tot2:=0;
  if (x='x') then inc(tot1);
  if (y='x') then inc(tot1);
  if (z='x') then inc(tot1);
  if (x='.') then inc(tot2);
  if (y='.') then inc(tot2);
  if (z='.') then inc(tot2);
  if (tot1=2) and (tot2=1) then flag:=true;
end;
begin
  for i:=1 to 4 do
  begin
    for j:=1 to 4 do
	  read(a[i,j]);
	readln;
  end;
  flag:=false;
  for i:=1 to 4 do
	for j:=1 to 2 do
	  deal(a[i,j],a[i,j+1],a[i,j+2]);
  for i:=1 to 2 do
	for j:=1 to 4 do
	  deal(a[i,j],a[i+1,j],a[i+2,j]);
  for i:=1 to 2 do
	for j:=1 to 2 do
	  deal(a[i,j],a[i+1,j+1],a[i+2,j+2]);
  for i:=3 to 4 do
	for j:=1 to 2 do
		deal(a[i,j],a[i-1,j+1],a[i-2,j+2]);
  if flag then writeln('YES') else writeln('NO');
end.
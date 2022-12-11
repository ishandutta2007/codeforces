var n,m,i,j,k:longint;
    tot,x:array[-10007..10007] of longint;
	flag,flagg:boolean;
begin
  readln(n,m);
  flag:=false;
  for i:=1 to m do
  begin
    flagg:=true;
    read(k);
    for j:=1 to k do
	begin
	  read(x[j]);
	  tot[x[j]]:=1;
	  if (tot[x[j]]+tot[-x[j]]>=2) then flagg:=false;
	end;
	readln;
	for j:=1 to k do
		tot[x[j]]:=0;
	if flagg then flag:=true;
  end;
  if flag then writeln('YES') else writeln('NO');
end.
var n,m,i,j,now:longint;
    f,g,h:array[0..100007] of longint;
	flag:boolean;
begin
  readln(n);m:=0;
  for i:=1 to n do
  begin
	read(f[i]);
    if (f[i]=i) then inc(m);
  end;
  for i:=1 to n do
	if not((f[i]=i) or (f[f[i]]=f[i])) then m:=0;
  if (m=0) then writeln(-1) else
  begin
    writeln(m);
    now:=0;
    for i:=1 to n do
	  if (f[i]=i) then
	  begin
	    inc(now);
	    h[now]:=i;
	    g[i]:=now;
	  end;
	for i:=1 to n do
	  write(g[f[i]],' ');
	writeln;
	for i:=1 to m do
	  write(h[i],' ');
	writeln;
  end;
end.
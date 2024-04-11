var i,j,n,x,y,k,t:longint;
    ch:array[0..100] of char;
begin
  readln(n,k);
  for i:=1 to n do
  begin
    read(ch[i]);
    if (ch[i]='T') then x:=i;
	if (ch[i]='G') then y:=i;
  end;
  readln;
  if (abs(x-y) mod k<>0) then writeln('NO') else
  begin
    t:=abs(x-y) div k;
    if (x-y>0) then k:=-k;
	for i:=1 to t do
	begin
	  x:=x+k;
	  if (ch[x]='#') then
	  begin
	    writeln('NO');
	    halt;
	  end;
	end;
	writeln('YES');
  end;
end.
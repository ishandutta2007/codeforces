var s:string;
    i,j,now,t1,t2,x,y:longint;
	flag:boolean;
	flagg:array[1..26] of longint;
	ans:array[1..2,1..13] of char;
	xx:char;
begin
  readln(s);
  flag:=true;
  for i:=1 to length(s)-1 do
	if (s[i]=s[i+1]) then flag:=false;
  if not(flag) then writeln('Impossible') else
  begin
    fillchar(flagg,sizeof(flagg),0);
    for i:=1 to 27 do
	  if (flagg[ord(s[i])-64]=0) then flagg[ord(s[i])-64]:=i else 
	  begin
	    t1:=flagg[ord(s[i])-64];
	    t2:=i;
	    xx:=s[i];
	  end;
	ans[1,13-(t2-t1-1) div 2]:=xx;
	x:=1;
	y:=14-(t2-t1-1) div 2;
	if (y=14) then
	begin
	  x:=2;
	  y:=13;
	end;
	for i:=t1+1 to 27 do
	if (i<>t2) then
	begin
	  ans[x,y]:=s[i];
	  if (x=1) then inc(y) else dec(y);
	  if (x=1) and (y=14) then begin x:=2;y:=13;end;
	  if (x=2) and (y=0) then begin x:=1;y:=1;end;
	end;
	for i:=1 to t1-1 do
	begin
	  	  ans[x,y]:=s[i];
	  if (x=1) then inc(y) else dec(y);
	  if (x=1) and (y=14) then begin x:=2;y:=13;end;
	  if (x=2) and (y=0) then begin x:=1;y:=1;end;
	end;
	for i:=1 to 2 do
    begin
	  for j:=1 to 13 do
		write(ans[i,j]);
	  writeln;
	end;
  end;
end.
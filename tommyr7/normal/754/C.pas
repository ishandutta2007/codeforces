var t,l,n,m,i,j,k,r:longint;
    na,spe:array[0..107] of string;
	f:array[0..107,0..107] of boolean;
	last:array[0..107,0..107] of longint;
	ans:array[0..107] of longint;
	x:char;
	flagt:boolean;
function deal(x:char):boolean;
begin
  if (x=':') or (x=' ') or (x='.') or (x=',') or (x='!') or (x='?') then exit(true);
  exit(false);
end;
function flagtry(x,y:longint):boolean;
var flag:boolean;
    i,j,k:longint;
begin
  for i:=1 to length(spe[x])-length(na[y])+1 do
  begin
    flag:=true;
    for j:=1 to length(na[y]) do
		if (spe[x,i+j-1]<>na[y,j]) then flag:=false;
	if flag then 
	begin
	  if (i=1) or deal(spe[x,i-1]) then
		if (i+length(na[y])-1=length(spe[x])) or deal(spe[x,i+length(na[y])]) then
		  exit(false);
    end;
  end;
  exit(true);
end;
begin
  readln(t);
  for l:=1 to t  do
  begin
    readln(n);
    for i:=1 to n-1 do
	begin
	  na[i]:='';
	  read(x);
	  while (x<>' ') do
	  begin
	    na[i]:=na[i]+x;
	    read(x);
	  end;
	end;
	readln(na[n]);
	readln(m);
	for i:=1 to m do
	  readln(spe[i]);
	fillchar(f,sizeof(f),false);
	f[0,0]:=true;
	fillchar(last,sizeof(last),0);
	for i:=1 to n do
	  f[0,i]:=true;
	for j:=1 to m do
if (spe[j,1]='?') then
begin
	  for i:=1 to n do
	  if flagtry(j,i) then
	  begin
if (j=1) then f[j,i]:=true else
begin
	    for k:=1 to n do
			if f[j-1,k] and (i<>k) then 
			begin
			  f[j,i]:=true;
		      last[j,i]:=k;
			end;
end;
	  end;
end
else
begin
  for i:=1 to n do
  begin
    flagt:=true;
    for k:=1 to length(na[i]) do
	  if na[i,k]<>spe[j,k] then flagt:=false;
	if (spe[j,length(na[i])+1]<>':') then flagt:=false;
	if flagt then
	begin
	if (j=1) then f[j,i]:=true
	else
	 begin
	  for r:=1 to n do
		if f[j-1,r] and (r<>i) then
		begin
		  f[j,i]:=true;
		  last[j,i]:=r;
		end;
	end;
	end;
  end;
end;
	flagt:=false;
	fillchar(ans,sizeof(ans),0);
	for i:=1 to n do
	  if f[m,i] then 
	  begin
	    ans[m]:=i;
	    flagt:=true;
	  end;
	if not(flagt) then writeln('Impossible') else
	begin
	for i:=m-1 downto 1 do
	  ans[i]:=last[i+1,ans[i+1]];
	for i:=1 to m do
	begin
if (spe[i,1]='?') then
begin
	  write(na[ans[i]]);
	  for j:=2 to length(spe[i]) do
		write(spe[i,j]);
end else write(spe[i]);
	  writeln;
	end;
	end;
  end;
  if not(t=l) then writeln;
end.
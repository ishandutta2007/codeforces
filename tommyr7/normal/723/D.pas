const tx:array[1..4] of longint=(0,0,1,-1);
	ty:array[1..4] of longint=(1,-1,0,0);
var n,m,k,i,j,tot,now,ans,ii,jj:longint;
    flag:boolean;
    ch:array[0..60,0..60] of char;
	vis:array[0..60,0..60] of boolean;
	r:array[0..60,0..60] of longint;
	area,b:array[0..2500] of longint;
procedure qsort(lx,rx:longint);
var i,j,m,t:longint;
begin
  i:=lx;
  j:=rx;
  m:=area[(i+j) div 2];
  repeat
	while (area[i]<m) do inc(i);
	while (area[j]>m) do dec(j);
	if (i<=j) then
	begin
	  t:=area[i];
	  area[i]:=area[j];
	  area[j]:=t;
	  t:=b[i];
	  b[i]:=b[j];
	  b[j]:=t;
	  inc(i);
	  dec(j);
	end;
  until (i>j);
  if (i<rx) then qsort(i,rx);
  if (j>lx) then qsort(lx,j);
end;
procedure tryit(x,y:longint);
var i,j,a,b:longint;
begin
  r[x,y]:=tot+1;
  vis[x,y]:=true;
  inc(now);
  if (x=1) or (x=n) or (y=1) or (y=m) then flag:=false;
  for i:=1 to 4 do
  begin
    a:=x+tx[i];
    b:=y+ty[i];
    if (1<=a) and (a<=n) and (1<=b) and (b<=m) then
	  if not(vis[a,b]) and (ch[a,b]='.') then tryit(a,b);
  end;
end;
procedure trycolor(t:longint);
var i,j:longint;
begin
  for i:=1 to n do
	for j:=1 to m do
		if (r[i,j]=t) then ch[i,j]:='*';
end;
begin
  readln(n,m,k);
  for i:=1 to n do
  begin
    for j:=1 to m do
		read(ch[i,j]);
	readln;
  end;
  fillchar(area,sizeof(area),0);
  fillchar(b,sizeof(b),0);
  fillchar(r,sizeof(r),0);
  tot:=0;
  fillchar(vis,sizeof(vis),false);
  for i:=2 to n-1 do
	for j:=2 to m-1 do
		if (ch[i,j]='.') and not(vis[i,j]) then 
		begin
		  now:=0;
		  flag:=true;
		  tryit(i,j);
		  if flag then
		  begin
		    inc(tot);
		    area[tot]:=now;
		  end
		  else
		  begin
		    for ii:=1 to n do
				for jj:=1 to m do
					if (r[ii,jj]=tot+1) then r[ii,jj]:=0;
		  end;
		end;
  for i:=1 to tot do
	b[i]:=i;
  qsort(1,tot);
  ans:=0;
  for i:=1 to tot-k do
  begin
    trycolor(b[i]);
	ans:=ans+area[i];
  end;
  writeln(ans);
  for i:=1 to n do
  begin
    for j:=1 to m do
		write(ch[i,j]);
	writeln;
  end;
end.
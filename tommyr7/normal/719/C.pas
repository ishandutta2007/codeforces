var n,k,i,j,t,tmp,now,noww,cnt:longint;
    a:array[1..200050] of char;
	flag:array[1..200050] of longint;
begin
  readln(n,t);
  for i:=1 to n do
  begin
	read(a[i]);
    if (a[i]='.') then cnt:=i;
  end;
  readln;
  fillchar(flag,sizeof(flag),0);
  if (ord(a[n])>=48+5) then flag[n]:=1;
  for i:=n-1 downto tmp+1 do
	if (ord(a[i])>=48+5) then flag[i]:=1 else if  ((flag[i+1]>0) and (a[i]='4')) then flag[i]:=2;
  now:=cnt+1;
  while (now<=n) and (flag[now]<>1) do inc(now);
  if (now=n+1) then
  begin
    j:=n;
    while (j>cnt) and (a[j]='0') do dec(j);
	if (j=cnt) then j:=cnt-1;
    for i:=1 to j do
	  write(a[i]);
	writeln;
  end
  else
  begin
    noww:=1;
    while (noww<=t) do
	begin
	  if (flag[now-1]=2) then flag[now-1]:=1;
	  now:=now-1;
	  if (flag[now]<>1) then break;
	  inc(noww);
	end;
	if (now=cnt) then
	begin
	  j:=cnt-1;
	  while (j>=1) do
	  begin
	    if (a[j]='9') then
		begin
		  a[j]:='0';
		  dec(j);
		end
		else
		begin
		  a[j]:=chr(ord(a[j])+1);
		  break;
	    end;
	  end;
	  if (j=0) then write('1');
	  for i:=1 to cnt-1 do
		write(a[i]);
	  writeln;
	end
	else
	begin
	  	  j:=now;
	  while (j>=1) do
	  begin
	    if (a[j]='9') then
		begin
		  a[j]:='0';
		  dec(j);
		  if (j=cnt) then j:=cnt-1;
		end
		else
		begin
		  a[j]:=chr(ord(a[j])+1);
		  break;
	    end;
	  end;
	  if (j=0) then write('1');
	  for i:=1 to cnt-1 do
		write(a[i]);
	  j:=now;
	  while (j>=cnt+1) and (a[j]='0') do dec(j);
	  if (j>=cnt+1) then
	  begin
	    write('.');
	    for i:=cnt+1 to j do
			write(a[i]);
	  end;
	  writeln;
	end;
  end;
end.
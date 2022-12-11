var s:array[0..3000] of char;
    i,j,k,n:longint;
	ans1,ans2,now,tot:longint;
procedure writef(x:longint);
var i,j:longint;
    t:array[1..100] of longint;
begin
  i:=0;
  j:=x;
  while (j<>0) do
  begin 
    inc(i);
    t[i]:=j mod 10;
    j:=j div 10;
  end;
  for k:=1 to i do
  begin
    write(t[i+1-k]);
    if (k mod 3=i mod 3) and (k<>i) then write('.');
  end;
end;
begin
  n:=0;
  while not(eoln) do
  begin
    inc(n);
    read(s[n]);
  end;
  readln;
  ans1:=0;ans2:=0;
  i:=1;
  while (i<=n) do
  begin
	while (i<=n) and  not((ord(s[i])>=48) and (ord(s[i])<=57)) do inc(i);
	now:=0;
	j:=i+1;
	while (j<=n) and ((s[j]='.') or ((ord(s[j])>=48) and (ord(s[j])<=57))) do inc(j);
	dec(j);
	tot:=0;
	for k:=j downto i do
		if (s[k]='.') then
		begin
		  tot:=k;
		  break;
		end;
	if (tot=0) or (tot=j-3) then
	begin
	  now:=0;
	  for k:=i to j do
		if (s[k]<>'.') then now:=now*10+ord(s[k])-48;
	  ans1:=ans1+now;
    end
	else
	begin
	  now:=0;
	  for k:=i to tot-1 do
		if (s[k]<>'.') then now:=now*10+ord(s[k])-48;
	  ans1:=ans1+now;
	  now:=0;
	  for k:=tot+1 to j do
		if (s[k]<>'.') then now:=now*10+ord(s[k])-48;
	  ans2:=ans2+now;
	end;
	i:=j+1;
  end;
  ans1:=ans1+ans2 div 100;
  ans2:=ans2 mod 100;
  if (ans1>0) then writef(ans1) else write('0');
  if (ans2>9) then writeln('.',ans2) else 
  if (ans2>0) then writeln('.0',ans2) else writeln;
end.
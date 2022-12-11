var n,i,j,max,ans,now:longint;
    flag:boolean;
    ch:array[0..500] of char;
function flagg(x:char):boolean;
begin
  if (65<=ord(x)) and (ord(x)<=65+25) then exit(true);
  if (97<=ord(x)) and (ord(x)<=97+25) then exit(true);
  exit(false);
end;
begin
  readln(n);
  for i:=1 to n do
	read(ch[i]);
  readln;
  max:=0;
  ans:=0;
  flag:=true;
  i:=1;
  now:=0;
  while (i<=n) do
  begin
    if flagg(ch[i]) then inc(now);
	if not(flagg(ch[i])) then
	begin
	  if flag then
	  begin
	    if (now>max) then max:=now;
	    now:=0;
	  end
	  else
	  begin
	    if (now>0) then inc(ans);
		now:=0;
	  end;
	end;
	if (ch[i]='(') then flag:=false;
	if (ch[i]=')') then flag:=true;
	inc(i);
  end;
	if (now>0) then
	begin
	  if not(flag) then inc(ans);
	  if flag and(now>max) then max:=now;
	end;
	writeln(max,' ',ans);
end.
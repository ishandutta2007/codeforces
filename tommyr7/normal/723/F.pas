var n,m,s,t,ds,dt,i,j,now1,now2,now3,now4,x:longint;
    a,b,father,fatherr,cs,ct:array[0..400000] of longint;
	flag1,flag2,flag,vis:array[0..400000] of boolean;
	flagg,flagt:boolean;
function tryit(i:longint):longint;
var k,t,p:longint;
begin
  k:=i;
  while (father[k]<>k) do k:=father[k];
  t:=i;
  while (t<>k) do
  begin
    p:=father[t];
    father[t]:=k;
    t:=p;
  end;
   exit(k);
end;
function tryit1(i:longint):longint;
var k,t,p:longint;
begin
  k:=i;
  while (fatherr[k]<>k) do k:=fatherr[k];
  t:=i;
  while (t<>k) do
  begin
    p:=fatherr[t];
    fatherr[t]:=k;
    t:=p;
  end;
   exit(k);
end;
procedure mdf(a1,b1:longint);
var i,j:longint;
begin
  i:=tryit(a1);
  j:=tryit(b1);
  if (i<>j) then father[j]:=i;
end;
begin
  readln(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(cs,sizeof(cs),0);
  fillchar(ct,sizeof(ct),0);
  for i:=1 to m do
	readln(a[i],b[i]);
  readln(s,t,ds,dt);
  for i:=1 to n do
    father[i]:=i;
  flagg:=false;
  for i:=1 to m do
  begin
	if (a[i]<>s) and (a[i]<>t) and (b[i]<>s) and (b[i]<>t) then mdf(a[i],b[i]);
	if (a[i]=s) and (b[i]=t) then flagg:=true;
	if (a[i]=t) and (b[i]=s) then flagg:=true;
  end;
  fillchar(flag1,sizeof(flag1),false);
  fillchar(flag2,sizeof(flag2),false);
  fillchar(flag,sizeof(flag),false);
  for i:=1 to n do
	if (i<>s) and (i<>t) then flag[tryit(i)]:=true;
  for i:=1 to m do
  begin
    if (a[i]=s) then 
	begin
	  flag1[tryit(b[i])]:=true;
	  cs[tryit(b[i])]:=b[i];
	end;
	if (b[i]=s) then 
	begin
	  flag1[tryit(a[i])]:=true;
	  cs[tryit(a[i])]:=a[i];
	end;
	if (a[i]=t) then 
	begin
	  flag2[tryit(b[i])]:=true;
	  ct[tryit(b[i])]:=b[i];
	end;
	if (b[i]=t) then 
	begin
	  flag2[tryit(a[i])]:=true;
	  ct[tryit(a[i])]:=a[i];
	end;
  end;
  now1:=0;
  now2:=0;
  now3:=0;
  now4:=0;
  for i:=1 to n do
	if (i<>s) and (i<>t) and flag[i] then
    begin
	  if flag1[i] and not(flag2[i]) then inc(now1);
	  if flag2[i] and not(flag1[i]) then inc(now2);
	  if flag1[i] and flag2[i] then inc(now3);
	  if not(flag1[i]) and not(flag2[i]) then inc(now4);
	end;
if (now3>0) and ((now1+now2+now3+1>ds+dt) or (now1+1>ds) or (now2+1>dt)) then
begin
  writeln('No');
  halt;
end
else if (now3=0) and (not(flagg) or (now1+now2+now3+2>ds+dt) or (now1+1>ds) or (now2+1>dt)) then
begin
    writeln('No');
    halt;
end
else
begin
  writeln('Yes');
  fatherr:=father;
  fillchar(father,sizeof(father),0);
  for i:=1 to n do
    father[i]:=i;
  flagt:=true;
  for i:=1 to n do
	if (i<>s) and (i<>t) and flag[i] then
	begin
	  if flag1[i] and not(flag2[i]) then
	  begin
	    dec(ds);
	    writeln(s,' ',cs[tryit1(i)]);
	    mdf(s,i);
	  end
	  else if flag2[i] and not(flag1[i]) then
	  begin
	    dec(dt);
	    writeln(t,' ',ct[tryit1(i)]);
	    mdf(t,i);
	  end;
	end;
  for i:=1 to n do
	if (i<>s) and (i<>t) and flag[i] then
	begin
	  if flag1[i] and flag2[i] then
	  begin
	    if flagt and (ds>0) and (dt>0) then
		begin
		  dec(ds);
		  dec(dt);
		  writeln(s,' ',cs[tryit1(i)]);
		  writeln(t,' ',ct[tryit1(i)]);
		  mdf(s,i);
		  mdf(t,i);
		  flagt:=false;
		end else
	    if (ds>0) then
		begin
		  dec(ds);
		  writeln(s,' ',cs[tryit1(i)]);
		  mdf(s,i);
		end else
		begin
		  dec(dt);
		  writeln(t,' ',ct[tryit1(i)]);
		  mdf(t,i);
		end;
	  end;
	end;
  if flagg and flagt then
  begin
    dec(ds);
    dec(dt);
    writeln(s,' ',t);
    mdf(s,t);
  end;
  for i:=1 to m do
	begin
	  if (tryit(a[i])<>tryit(b[i])) and (a[i]<>s) and (b[i]<>s) and (a[i]<>t) and (b[i]<>t) then
	  begin
	    writeln(a[i],' ',b[i]);
	    mdf(a[i],b[i]);
	  end
	end;
end;
end.
const dx:array[1..8] of longint=(0,1,1,1,0,-1,-1,-1);
    dy:array[1..8] of longint=(1,1,0,-1,-1,-1,0,1);
var flag,now:array[-200..200,-200..200,1..8] of boolean;
    flag1:array[-200..200,-200..200] of boolean;
    n,i,j,k,ans,x,y:longint;
	t:array[0..200] of longint;
procedure deal(x,y,k,tt:longint);
var i,j,t1,t2,nowx,nowy:longint;
begin
  t1:=tt-1;
  if (t1<=0) then t1:=t1+8;
  t2:=tt+1;
  if (t2>=9) then t2:=t2-8;
  nowx:=x;nowy:=y;
  for i:=1 to t[k] do
  begin
    nowx:=nowx+dx[t1];
    nowy:=nowy+dy[t1];
    flag1[nowx,nowy]:=true;
  end;
  now[nowx,nowy,t1]:=true;
  nowx:=x;nowy:=y;
  for i:=1 to t[k] do
  begin
    nowx:=nowx+dx[t2];
    nowy:=nowy+dy[t2];
    flag1[nowx,nowy]:=true;
  end;
  now[nowx,nowy,t2]:=true;
end;
begin
  readln(n);
  fillchar(t,sizeof(t),0);
  for i:=1 to n do
	read(t[i]);
  readln;
  fillchar(flag,sizeof(flag),false);
  fillchar(flag1,sizeof(flag1),false);
  for i:=1 to t[1] do
    flag1[1,i]:=true;
  flag[1,t[1],1]:=true;
  for i:=2 to n do
  begin
    fillchar(now,sizeof(now),false);
    for x:=-200 to 200 do
	  for y:=-200 to 200 do
		for k:=1 to 8 do
	    if (flag[x,y,k]) then
	      deal(x,y,i,k);
    for x:=-200 to 200 do
	  for y:=-200 to 200 do
		for k:=1 to 8 do
		flag[x,y,k]:=now[x,y,k];
  end;
  ans:=0;
  for x:=-200 to 200 do
	for y:=-200 to 200 do
	  if flag1[x,y] then inc(ans);
  writeln(ans);
end.
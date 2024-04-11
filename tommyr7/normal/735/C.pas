type matrix=array[1..2,1..2] of int64;
var i,j,k,l:longint;
    t,goal,lx,rx,mid:int64;
	a,b,ans:matrix;
function multiply(a,b:int64):int64;
var ans,now,left:int64;
begin
  ans:=0;
  now:=a;
  left:=b;
  while (left>0) do
  begin
    if (left mod 2=1) then ans:=(ans+now);
	left:=left div 2;
	now:=(now+now);
  end;
  exit(ans);
end;
function time(a,b:matrix):matrix;
var ans:matrix;
    i,j,k:longint;
begin
  fillchar(ans,sizeof(ans),0);
  for i:=1 to 2 do
	for j:=1 to 2 do
		for k:=1 to 2 do
			ans[i,j]:=(ans[i,j]+multiply(a[i,k],b[k,j]));
  exit(ans);
end;
function power(x:matrix;t:int64):matrix;
var ans,now:matrix;
    left:int64;
begin
  fillchar(ans,sizeof(ans),0);ans[1,1]:=1;ans[2,2]:=1;
  left:=t;
  now:=x;
  while (left>0) do
  begin
    if (left mod 2=1) then ans:=time(ans,now);
	left:=left div 2;
	now:=time(now,now);
  end;
  exit(ans);
end;
function check(x:int64):boolean;
begin
	t:=x+3;
    fillchar(a,sizeof(a),0);a[1,2]:=1;
    fillchar(b,sizeof(b),0);b[1,1]:=1;b[2,2]:=0;b[1,2]:=1;b[2,1]:=1;
    b:=power(b,t-1);
    ans:=time(a,b);
    if (ans[1,1]>goal) then exit(false) else exit(true);
end;
begin
  readln(goal);
  lx:=1;
  rx:=95;
  while (rx-lx>1) do
  begin
    mid:=(lx+rx) div 2;
    if (check(mid)) then lx:=mid else rx:=mid;
  end;
  if (check(rx)) then writeln(rx) else writeln(lx);
end.
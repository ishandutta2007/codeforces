var n,m,k,i,j,x,y,tota,totb,ans,t:longint;
    a,b,father:array[0..3000] of longint;
	f:array[0..3000,0..3000] of longint;
	vis:array[0..3000] of boolean;
function fa(x:longint):longint;
begin
  if (father[x]<>x) then father[x]:=fa(father[x]);
  exit(father[x]);
end;
procedure mdf(u,v:longint);
var x,y:longint;
begin
  x:=fa(u);y:=fa(v);
  if (x<>y) then father[y]:=x;
end;
procedure dp(x,y:longint);
var i,j:longint;
begin
  for j:=0 to k do
  begin
    if (f[t-1,j]>f[t,j]) then f[t,j]:=f[t-1,j];
    if (j>0) and (f[t,j]<f[t,j-1]) then f[t,j]:=f[t,j-1];
	if (j>=x) then
	  if (f[t-1,j-x]+y>f[t,j]) then f[t,j]:=f[t-1,j-x]+y;
  end;
end;
begin
  readln(n,m,k);
  for i:=1 to n do
	read(a[i]);
  readln;
  for i:=1 to n do
	read(b[i]);
  readln;
  fillchar(father,sizeof(father),0);
  for i:=1 to n do
	father[i]:=i;
  for i:=1 to m do
  begin
    readln(x,y);
    mdf(x,y);
  end;
  fillchar(f,sizeof(f),0);
  fillchar(vis,sizeof(vis),false);
  fillchar(f,sizeof(f),0);
  t:=0;
  for i:=1 to n do
	if not(vis[i]) then
    begin
	  inc(t);
	  tota:=0;totb:=0;
	  x:=fa(i);
	  for j:=1 to n do
		if (fa(j)=x) then 
		begin
		  vis[j]:=true;
		  tota:=tota+a[j];totb:=totb+b[j];
		  dp(a[j],b[j]);
		end;
      dp(tota,totb);
	end;
  ans:=0;
  writeln(f[t,k]);
end.
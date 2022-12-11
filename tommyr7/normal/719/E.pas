type arr=array[1..2,1..2] of int64;
nodetype=record
	sum,cover:arr;
    flag:boolean;
	lx,rx:longint;
end;
const modp=1000000007;
	fff:arr=((1,0),(0,0));
    one:arr=((1,0),(0,1));
    onee:arr=((0,0),(0,0));
    oneee:arr=((1,1),(1,0));
var t:array[0..400050] of nodetype;
    a:array[0..100050] of longint;
    i,j,n,m,op,x,y,z:longint;
    xx:arr;
    x1,y1:int64;
function plus(a,b:arr):arr;
var ans:arr;
	i,j:longint;
begin
  for i:=1 to 2 do
  begin
	ans[i,1]:=(a[i,1]+b[i,1]) mod modp;
    ans[i,2]:=(a[i,2]+b[i,2]) mod modp;
  end;
  exit(ans);
end;
function time(a,b:arr):arr;
var ans:arr;
	i,j,k:longint;
begin
  for i:=1 to 2 do
	for j:=1 to 2 do
		ans[i,j]:=(a[i,1]*b[1,j]+a[i,2]*b[2,j]) mod modp;
  exit(ans);
end;
function try1(i:longint):arr;
var ans,now:arr;
    left:longint;
begin
  ans:=one;
  now:=oneee;
  left:=i;
  while (left>0) do
  begin
    if (left mod 2=1) then ans:=time(ans,now);
	left:=left div 2;
	now:=time(now,now);
  end;
  exit(ans);
end;
procedure build(node,lx,rx:longint);
var mid:longint;
begin
  if (lx=rx) then
  begin
    t[node].sum:=time(fff,try1(a[lx]-1));
	t[node].cover:=one;
    t[node].lx:=lx;
    t[node].rx:=rx;
  end
  else
  begin
    mid:=(lx+rx) div 2;
    build(node*2,lx,mid);
    build(node*2+1,mid+1,rx);
    t[node].sum:=plus(t[node*2].sum,t[node*2+1].sum);
    t[node].cover:=one;
    t[node].lx:=lx;
    t[node].rx:=rx;
  end;
end;
procedure pushdown(node:longint);
begin
  if not(t[node].flag) then exit;
  t[node*2].cover:=time(t[node*2].cover,t[node].cover);
  t[node*2+1].cover:=time(t[node*2+1].cover,t[node].cover);
  t[node*2].sum:=time(t[node*2].sum,t[node].cover);
  t[node*2+1].sum:=time(t[node*2+1].sum,t[node].cover);
  t[node*2].flag:=true;
  t[node*2+1].flag:=true;
  t[node].cover:=one;
  t[node].flag:=false;
end;
procedure updata(node:longint);
var mid:longint;
begin
  if (t[node].lx>y) or (t[node].rx<x) then exit;
  if (t[node].lx>=x) and (t[node].rx<=y) then
  begin
    t[node].cover:=time(t[node].cover,xx);
	t[node].sum:=time(t[node].sum,xx);
    t[node].flag:=true;
	exit;
  end;
  pushdown(node);
  mid:=(t[node].lx+t[node].rx) div 2;
  updata(node*2);
  updata(node*2+1);
  t[node].sum:=plus(t[node*2].sum,t[node*2+1].sum);
end;
function query(node:longint):arr;
var mid:longint;
begin
  if (t[node].lx>y) or (t[node].rx<x) then exit(onee);
  if (t[node].lx>=x) and (t[node].rx<=y) then exit(t[node].sum);
  pushdown(node);
  mid:=(t[node].lx+t[node].rx) div 2;
  exit(plus(query(node*2),query(node*2+1)));
end;
begin
  readln(n,m);
  fillchar(t,sizeof(t),0);
  for i:=1 to n do
	read(a[i]);
  readln;
  build(1,1,n);
  for i:=1 to m do
  begin
    read(op);
    if (op=1) then
    begin
	  readln(x,y,z);
	  xx:=try1(z);
	  updata(1);
	end
	else
	begin
	  readln(x,y);
	  writeln(query(1)[1,1]);
	end;
  end;
end.
uses math;
type nodetype=record
	left,right,maxx:int64;
end;
var n,i,j,tot:longint;
    a,b,h,t,tt:array[0..200007] of longint;
	tree:array[0..800007] of nodetype;
	s,f:array[0..100007] of int64;
    now:int64;
procedure qsort1(lx,rx:longint);
var i,j,m,t,m1:longint;
begin
  i:=lx;j:=rx;m:=random(rx-lx+1)+lx;m1:=a[m];m:=b[m];
  repeat
	while (b[i]<m) or((b[i]=m) and (a[i]<m1))do inc(i);
	while (b[j]>m) or ((b[j]=m) and (a[j]>m1))do dec(j);
	if (i<=j) then
	begin
	  t:=h[i];h[i]:=h[j];h[j]:=t;
	  t:=a[i];a[i]:=a[j];a[j]:=t;
	  t:=b[i];b[i]:=b[j];b[j]:=t;
	  inc(i);dec(j);
	end;
  until (i>j);
  if (i<rx) then qsort1(i,rx);
  if (lx<j) then qsort1(lx,j);
end;
procedure qsort2(lx,rx:longint);
var i,j,m,t1:longint;
begin
  i:=lx;j:=rx;m:=t[random(rx-lx+1)+lx];
  repeat
	while (t[i]<m) do inc(i);
	while (t[j]>m) do dec(j);
	if (i<=j) then
	begin
	  t1:=t[i];t[i]:=t[j];t[j]:=t1;
	  inc(i);dec(j);
	end;
  until (i>j);
  if (i<rx) then qsort2(i,rx);
  if (lx<j) then qsort2(lx,j);
end;
function find(x:longint):longint;
var left,right,mid:longint;
begin
  left:=1;right:=tot;
  while (right-left>1) do
  begin
    mid:=(left+right) div 2;
    if (tt[mid]<=x) then left:=mid else right:=mid;
  end;
  if (tt[left]=x) then exit(left) else exit(right);
end;
procedure build(node,lx,rx:longint);
var mid:longint;
begin
  tree[node].left:=lx;tree[node].right:=rx;
  if (lx<rx) then
  begin
    mid:=(lx+rx) div 2;
    build(node*2,lx,mid);build(node*2+1,mid+1,rx);
  end;
end;
function query(node,a,b:longint):int64;
var mid:longint;
begin
  if (tree[node].right<a) or (tree[node].left>b) then exit(0);
  if (tree[node].left>=a) and (tree[node].right<=b) then exit(tree[node].maxx);
  exit(max(query(node*2,a,b),query(node*2+1,a,b)));
end;
procedure updata(node,pos:longint;val:int64);
var mid:longint;
begin
  if (tree[node].left=tree[node].right) then
  begin
    tree[node].maxx:=max(tree[node].maxx,val);
  end else
  begin
    mid:=(tree[node].left+tree[node].right) div 2;
    if (mid<pos) then updata(node*2+1,pos,val) else updata(node*2,pos,val);
	tree[node].maxx:=max(tree[node*2].maxx,tree[node*2+1].maxx);
  end;
end;
begin
  randomize;
  readln(n);
  for i:=1 to n do
  begin
	readln(a[i],b[i],h[i]);
    t[i*2-1]:=a[i];t[i*2]:=b[i];
  end;
  qsort2(1,n*2);
  tot:=1;
  tt[1]:=t[1];
  for i:=2 to n*2 do
	if (t[i]<>t[i-1]) then
	begin
	  inc(tot);
	  tt[tot]:=t[i];
	end;
  for i:=1 to n do
  begin
    a[i]:=find(a[i]);
    b[i]:=find(b[i]);
  end;
  qsort1(1,n);
  fillchar(f,sizeof(f),0);
  fillchar(s,sizeof(s),0);
  build(1,1,tot);
  for i:=1 to n do
  begin
    f[i]:=h[i];
    now:=query(1,a[i]+1,b[i]);
    if (now>=0) then f[i]:=h[i]+now;
	updata(1,b[i],f[i]);
  end;
  writeln(query(1,1,tot));
end.
var n,i,j,ans,now,l,d,length:longint;
    t,w,heap:array[0..300007] of int64;
	rk:array[0..300007] of longint;
	tmp:int64;
procedure insert(x:int64);
var i,j:longint;
    t:int64;
begin
  inc(length);
  heap[length]:=x;
  i:=length;
  while (i div 2>0) do
  begin
    j:=i div 2;
    if (heap[i]>=heap[j]) then break;
	t:=heap[i];
	heap[i]:=heap[j];
	heap[j]:=t;
	i:=j;
  end;
end;
procedure delete;
var i,j:longint;
	t:int64;
begin
  heap[1]:=heap[length];
  dec(length);
  i:=1;
  while (i*2<=length) do
  begin
    j:=i*2;
    if (j<length) and (heap[j]>heap[j+1]) then inc(j);
	if (heap[j]>=heap[i]) then break;
	t:=heap[j];
	heap[j]:=heap[i];
	heap[i]:=t;
	i:=j;
  end;
end;
procedure qsort(lx,rx:longint);
var i,j,ttt:longint;
    m,tt:int64;
begin
  i:=lx;
  j:=rx;
  m:=t[rk[(i+j) div 2]];
  repeat
	while (t[rk[i]]<m) do inc(i);
	while (t[rk[j]]>m) do dec(j);
	if (i<=j) then
	begin
	  ttt:=rk[i];
	  rk[i]:=rk[j];
	  rk[j]:=ttt;
	  inc(i);
	  dec(j);
	end;
  until (i>j);
  if (i<rx) then qsort(i,rx);
  if (j>lx) then qsort(lx,j);
end;
begin
  readln(n);
  fillchar(t,sizeof(t),0);
  fillchar(w,sizeof(w),0);
  for i:=1 to n do
  begin
    rk[i]:=i;
	readln(t[i],w[i]);
  end;
  tmp:=t[1];
  qsort(1,n);
  fillchar(heap,sizeof(heap),0);
  l:=n+1;
  now:=0;
  d:=0;
  length:=0;
  ans:=n;
  while (l>=1) do
  begin
    while (l>1) and (t[rk[l-1]]>tmp) do
	begin
	  dec(l);
	  if (rk[l]<>1) then
	  begin
	  insert(w[rk[l]]-t[rk[l]]+1);
	  inc(now);
	  end;
	end;
	if (now-d+1<ans) then ans:=now-d+1;
	if (length>0) and (tmp>=heap[1]) then
	begin
	  tmp:=tmp-heap[1];
	  delete;
	  inc(d);
	end else break;
  end;
  writeln(ans);
end.
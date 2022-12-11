uses math;
var n,i,j,tot,u,v,q:longint;
    last,pre,other,a:array[0..500007] of longint;
	sum,max:array[0..500007] of int64;
	flag:boolean;
	max1,max2,ans:int64;
procedure insert(u,v:longint);
begin
  inc(tot);
  other[tot]:=v;
  pre[tot]:=last[u];
  last[u]:=tot;
end;
procedure dfs(u,father:longint);
var q,v,t:longint;
begin
  q:=last[u];t:=0;sum[u]:=a[u];max[u]:=-999999999999999;
  while (q>0) do
  begin
    v:=other[q];
    if (v<>father) then
	begin
	  dfs(v,u);
	  sum[u]:=sum[u]+sum[v];
	  if (max[v]>max[u]) then max[u]:=max[v];
	  inc(t);
	  if (t>1) then flag:=true;
	end;
	q:=pre[q];
  end;
  if (sum[u]>max[u]) then max[u]:=sum[u];
end;
procedure dfs1(u,father:longint);
var max1,max2:int64;
    q,v,t:longint;
begin
  max1:=-999999999999999 div 2;
  max2:=-999999999999999 div 2;
  q:=last[u];t:=0;
  while (q>0) do
  begin
    v:=other[q];
    if (v<>father) then
	begin
	  dfs1(v,u);
	  inc(t);
    if (max[v]>max1) then 
    begin
	  max2:=max1;
	  max1:=max[v];
	end else
	  if (max[v]>max2) then max2:=max[v];
	end;
	q:=pre[q];
  end;
  if (t>=2) and (max1+max2>ans) then ans:=max1+max2;
end;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(last,sizeof(last),0);
  fillchar(pre,sizeof(pre),0);
  fillchar(other,sizeof(other),0);
  for i:=1 to n do
	read(a[i]);
  readln;
  tot:=0;
  for i:=1 to n-1 do
  begin
    readln(u,v);
    insert(u,v);
    insert(v,u);
  end;
  flag:=false;
  fillchar(sum,sizeof(sum),0);
  fillchar(max,sizeof(max),0);
  dfs(1,0);
  if not(flag) then
  begin
    writeln('Impossible');
    halt;
  end;
  ans:=-999999999999999 div 2;
  dfs1(1,0);
  writeln(ans);
end.
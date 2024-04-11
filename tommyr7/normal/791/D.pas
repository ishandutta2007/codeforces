var n,k,i,j,tot,x,y:longint;
    last,pre,other:array[0..400007] of longint;
	f:array[0..200007,0..5] of longint;
	sum,size:array[0..200007] of int64;
	ans:int64;
procedure insert(x,y:longint);
begin
  inc(tot);
  other[tot]:=y;pre[tot]:=last[x];last[x]:=tot;
end;
procedure dfs(u,father:longint);
var q,v,i,t:longint;
    anss:int64;
	f1:array[0..5] of longint;
begin
  size[u]:=1;
  for i:=1 to k-1 do
	f[u,i]:=0;
  f[u,0]:=1;
  q:=last[u];
  while (q>0) do
  begin
    v:=other[q];
    if (v<>father) then
	begin
	  dfs(v,u);
	  sum[u]:=sum[u]+sum[v]+f[v,k-1];
	  size[u]:=size[u]+size[v];
	  for i:=0 to k-1 do
		f[u,(i+1) mod k]:=f[u,(i+1) mod k]+f[v,i];
	end;
    q:=pre[q];
  end;
  q:=last[u];
  anss:=0;ans:=ans+sum[u]+size[u]-f[u,0];
  while (q>0) do
  begin
    v:=other[q];
    if (v<>father) then
	  ans:=ans+int64(int64(sum[v]+f[v,k-1])*int64(size[u]-size[v]-1));
	q:=pre[q];
  end;
//writeln(u,' ',ans,' ',anss);
  q:=last[u];
  while (q>0) do
  begin
    v:=other[q];
    if (v<>father) then
	begin
	  for i:=0 to k-1 do
		f1[i]:=f[u,i]-f[v,(i+k-1) mod k];
	  dec(f1[0]);
	  for i:=0 to k-1 do
		for j:=0 to k-1 do
		begin
		    t:=(i+j);if (t=0) then t:=0 else if (t<=k) then t:=1 else t:=2;
			anss:=anss+int64(int64(int64(f[v,(i-1+k) mod k])*int64(f1[j]))*t);
		end;
	end;
	q:=pre[q];
  end;
  ans:=ans+anss div 2;
//writeln(u,' ',ans,' ',anss);
end;
begin
  readln(n,k);
  tot:=0;ans:=0;
  for i:=1 to n-1 do
  begin
    readln(x,y);
    insert(x,y);insert(y,x);
  end;
  dfs(1,0);
  writeln(ans);
end.
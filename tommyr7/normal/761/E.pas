const tx:array[1..4] of longint=(0,-1,1,0);
    ty:array[1..4] of longint=(1,0,0,-1);
var n,i,j,l:longint;
    a,b,tot,last,pre,other:array[0..107] of longint;
	x,y,bin:array[0..107] of int64;
	ans:boolean;
procedure insert(u,v:longint);
begin
  inc(l);
  other[l]:=v;
  pre[l]:=last[u];
  last[u]:=l;
end;
procedure dfs(u,father,loc:longint;now:int64);
var q,v,t:longint;
begin
  t:=0;
  q:=last[u];
  while (q>0) do
  begin
    v:=other[q];
    if (v<>father) then
	begin
	  inc(t);
	  if (t+loc=5) then inc(t);
	  x[v]:=x[u];y[v]:=y[u];
	  if (tx[t]=1) then x[v]:=x[v]+bin[n-now];
	  if (tx[t]=-1) then x[v]:=x[v]-bin[n-now];
	  if (ty[t]=1) then y[v]:=y[v]+bin[n-now];
	  if (ty[t]=-1) then y[v]:=y[v]-bin[n-now];
	  dfs(v,u,t,now+1);
	end;
	q:=pre[q];
  end;
end;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(tot,sizeof(tot),0);
  fillchar(last,sizeof(last),0);
  fillchar(pre,sizeof(pre),0);
  fillchar(other,sizeof(other),0);
  fillchar(x,sizeof(x),0);
  fillchar(y,sizeof(y),0);
  fillchar(bin,sizeof(bin),0);
  bin[0]:=1;
  for i:=1 to n do
	bin[i]:=bin[i-1]+bin[i-1]+bin[i-1];
  l:=0;
  for i:=1 to n-1 do
  begin
    readln(a[i],b[i]);
    inc(tot[a[i]]);inc(tot[b[i]]);
    insert(a[i],b[i]);insert(b[i],a[i]);
  end;
  ans:=true;
  for i:=1 to n do
	if (tot[i]>4) then ans:=false;
  if not(ans) then writeln('NO') else
  begin
    writeln('YES');
    x[1]:=0;y[1]:=0;
    dfs(1,0,-1,0);
    for i:=1 to n do
	  writeln(x[i],' ',y[i]);
  end;
end.
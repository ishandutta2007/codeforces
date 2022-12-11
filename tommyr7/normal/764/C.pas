var n,i,j,tot,m,q,cnt,v,ans:longint;
    last,pre,other,c,x,y,r:array[0..200007] of longint;
procedure insert(u,v:longint);
begin
  inc(tot);
  other[tot]:=v;pre[tot]:=last[u];last[u]:=tot;
end;
begin
  readln(n);
  fillchar(r,sizeof(r),0);
  tot:=0;
  for i:=1 to n-1 do
  begin
    readln(x[i],y[i]);
    insert(x[i],y[i]);insert(y[i],x[i]);
  end;
  for i:=1 to n do
	read(c[i]);
  readln;
  cnt:=0;
  for i:=1 to n do
  begin
    q:=last[i];
    while (q>0) do
	begin
	  v:=other[q];
	  if (c[v]<>c[i]) then
	  begin
	    inc(r[v]);inc(r[i]);inc(cnt);
	  end;
	  q:=pre[q];
	end;
  end;
  ans:=-1;
  for i:=1 to n do
    if (r[i]=cnt) then ans:=i;
  if (ans=-1) then writeln('NO') else
  begin
    writeln('YES');
    writeln(ans);
  end;
end.
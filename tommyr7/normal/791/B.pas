var n,m,i,j,x,y:longint;
    father,rank:array[0..150007] of longint;
	vis:array[0..150007] of boolean;
	ans:int64;
function find(x:longint):longint;
begin
  if (x=father[x]) then exit(x);
  father[x]:=find(father[x]);
  exit(father[x]);
end;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    father[i]:=i;
    rank[i]:=1;
  end;
  for i:=1 to m do
  begin
    readln(x,y);
    x:=find(x);y:=find(y);
    if (x<>y) then
    begin
	  if (rank[x]<rank[y]) then
	  begin
	    rank[y]:=rank[y]+rank[x];
	    father[x]:=y;
	  end else
	  begin
	    rank[x]:=rank[x]+rank[y];
	    father[y]:=x;
	  end;
	end;
  end;
  ans:=0;
  fillchar(vis,sizeof(vis),false);
  for i:=1 to n do
  begin
    x:=find(i);
    if not(vis[x]) then
    begin
	  vis[x]:=true;
	  ans:=ans+int64(int64(rank[x])*int64(rank[x]-1)) div 2;
	end;
  end;
  if (ans<>m) then writeln('NO') else writeln('YES');
end.
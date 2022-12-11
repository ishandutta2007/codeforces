var a,b,anss:array[0..100050] of int64;
    vis:array[0..100050] of boolean;
	father:array[0..100050] of longint;
    n,i,j,tot:longint;
	ans:int64;
function try1(i:longint):longint;
var k,t,p:longint;
begin
  k:=i;
  while (father[k]<>k) do k:=father[k];
  t:=i;
  while (t<>k) do
  begin
    p:=father[t];
    father[t]:=k;
    t:=p;
  end;
   exit(k);
end;
procedure mdf(a1,b1:longint);
var i,j:longint;
begin
  i:=try1(a1);
  j:=try1(b1);
  if (i<>j) then
  begin
    father[j]:=i;
    a[i]:=a[i]+a[j];
  end;
end;
begin
  readln(n);
  for i:=1 to n do
	father[i]:=i;
  fillchar(vis,sizeof(vis),false);
  for i:=1 to n do
	read(a[i]);
  readln;
  for i:=1 to n do
	read(b[i]);
  readln;
  ans:=0;
  tot:=0;
  fillchar(anss,sizeof(anss),0);
  for i:=n downto 1 do
  begin
    inc(tot);
    anss[tot]:=ans;
    vis[b[i]]:=true;
    if (b[i]>=2) and vis[b[i]-1] then mdf(b[i],b[i]-1);
	if (b[i]<=n-1) and vis[b[i]+1] then mdf(b[i],b[i]+1);
	if (a[try1(b[i])]>ans) then ans:=a[try1(b[i])];
  end;
  for i:=n downto 1 do
	writeln(anss[i]);
end.
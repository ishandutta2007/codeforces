var n,m,i,j,k,left,right,mid:longint;
    d,a,pos:array[0..100000] of longint;
	vis:array[0..100000] of boolean;
function tryit(x:longint):boolean;
var i,j,tot:longint;
begin
  fillchar(pos,sizeof(pos),0);
  fillchar(vis,sizeof(vis),false);
  for i:=x downto 1 do
    if (d[i]<>0) and not(vis[d[i]]) then
	begin
	  pos[i]:=d[i];
	  vis[d[i]]:=true;
	end;
  tot:=0;
  for i:=1 to x do
    if (pos[i]=0) then inc(tot) else
	begin
	  if (a[pos[i]]>tot) then exit(false);
	  tot:=tot-a[pos[i]];
	end;
  for i:=1 to m do
	if not(vis[i]) then exit(false);
  exit(true);
end;
begin
  readln(n,m);
  fillchar(d,sizeof(d),0);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
	read(d[i]);
  readln;
  for i:=1 to m do
	read(a[i]);
  readln;
  left:=0;
  right:=n;
  while (right-left>1) do
  begin
    mid:=(right+left) div 2;
    if tryit(mid) then right:=mid else left:=mid;
  end;
  if tryit(left) then writeln(left)
  else if tryit(right) then writeln(right)
  else writeln(-1);
end.
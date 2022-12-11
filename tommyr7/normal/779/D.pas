var s1,s2:array[0..200007] of char;
    r,last,next:array[0..200007] of longint;
	n,m,i,j,left,right,mid:longint;
	ch:char;
function tryit(x:longint):boolean;
var i,j,now:longint;
begin
  for i:=1 to n do
  begin
    last[i]:=i-1;
    next[i]:=i+1;
  end;
  next[0]:=1;
  last[0]:=0;
  last[n+1]:=n;
  next[n+1]:=n+2;
  next[n+2]:=n+2;
  for i:=1 to x do
  begin
    next[last[r[i]]]:=next[r[i]];
    last[next[r[i]]]:=last[r[i]];
  end;
  now:=next[0];
  for i:=1 to m do
  begin
    while (now<n+1) and (s1[now]<>s2[i]) do now:=next[now];
	now:=next[now];
  end;
  if (now<=n+1) then exit(true) else exit(false);
end;
begin
  n:=0;m:=0;
  while not(eoln) do
  begin
    inc(n);
    read(s1[n]);
  end;
  readln;
  while not(eoln) do
  begin
    inc(m);
    read(s2[m]);
  end;
  readln;
  for i:=1 to n do
	read(r[i]);
  readln;
  left:=0;
  right:=n;
  while (right-left>1) do
  begin
    mid:=(left+right) div 2;
    if tryit(mid) then left:=mid else right:=mid;
  end;
  if (tryit(right)) then writeln(right) else writeln(left);
end.
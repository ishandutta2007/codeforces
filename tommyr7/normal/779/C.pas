var n,k,i,j,tot,cnt:longint;
    a,b,a1,b1,c1:array[0..200007] of longint;
	ans:int64;
procedure qsort(lx,rx:longint);
var i,j,m,t:longint;
begin
  i:=lx;j:=rx;m:=c1[random(rx-lx+1)+lx];
  repeat
	while (c1[i]<m) do inc(i);
	while (c1[j]>m) do dec(j);
	if (i<=j) then
	begin
	  t:=a1[i];a1[i]:=a1[j];a1[j]:=t;
	  t:=b1[i];b1[i]:=b1[j];b1[j]:=t;
	  t:=c1[i];c1[i]:=c1[j];c1[j]:=t;
	  inc(i);dec(j);
    end;
  until (i>j);
  if (i<rx) then qsort(i,rx);
  if (j>lx) then qsort(lx,j);
end;
begin
  randomize;
  readln(n,k);
  tot:=0;cnt:=0;ans:=0;
  for i:=1 to n do
	read(a[i]);
  readln;
  for i:=1 to n do
	read(b[i]);
  readln;
  for i:=1 to n do
	if (b[i]>=a[i]) then
    begin
	  ans:=ans+a[i];
	  inc(tot);
	end else
	begin
	  inc(cnt);
	  a1[cnt]:=a[i];b1[cnt]:=b[i];c1[cnt]:=a1[cnt]-b1[cnt];
	end;
  if (tot<k) then
  begin
    qsort(1,cnt);
    for i:=1 to k-tot do
	  ans:=ans+a1[i];
	for i:=k-tot+1 to cnt do
	  ans:=ans+b1[i];
	writeln(ans);
  end else
  begin
    for i:=1 to cnt do
	  ans:=ans+b1[i];
	writeln(ans);
  end;
end.
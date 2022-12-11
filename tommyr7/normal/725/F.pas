var a1,b1,a2,b2,i,n,tot:longint;
    ans:int64;
	f:array[0..400010] of longint;
procedure qsort(lx,rx:longint);
var i,j,m,t:longint;
begin
  i:=lx;
  j:=rx;
  m:=f[(i+j) div 2];
  repeat
	while (f[i]<m) do inc(i);
	while (f[j]>m) do dec(j);
	if (i<=j) then
	begin
	  t:=f[i];
	  f[i]:=f[j];
	  f[j]:=t;
	  inc(i);
	  dec(j);
	end;
  until (i>j);
  if (i<rx) then qsort(i,rx);
  if (j>lx) then qsort(lx,j);
end;
begin
  readln(n);
  ans:=0;
  fillchar(f,sizeof(f),0);
  tot:=0;
  for i:=1 to n do
  begin
    readln(a1,b1,a2,b2);
    if ((a1<=b2) and (b1<=a2)) then continue;
	if (a1+b1<=a2+b2) then
	begin
	  if (a1>b2) then ans:=ans+(a1-b2) else ans:=ans+(a2-b1);
	  continue;
	end;
	ans:=ans-(b1+b2);
	inc(tot);
	f[tot]:=a1+b1;
	inc(tot);
	f[tot]:=a2+b2;
  end;
  qsort(1,tot);
  i:=2;
  while (i<=tot) do
  begin
    ans:=ans+f[i];
    i:=i+2;
  end;
  writeln(ans);
end.
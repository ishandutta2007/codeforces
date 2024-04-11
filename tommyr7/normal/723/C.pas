var n,m,i,j,ans,ans1:longint;
    a,flag,flag1,anss:array[0..3000] of longint;
begin
  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
	read(a[i]);
  readln;
  write(n div m,' ');
  ans:=n div m;
  fillchar(flag,sizeof(flag),0);
  for i:=1 to n do
	if (a[i]<=m) then inc(flag[a[i]]);
  ans1:=0;
  for i:=1 to m do
	if (flag[i]<ans) then ans1:=ans1+ans-flag[i];
  writeln(ans1);
  fillchar(flag1,sizeof(flag1),0);
  fillchar(anss,sizeof(anss),0);
  for i:=1 to n do
  begin
    if (a[i]<=m) then
	begin
	  if (flag1[a[i]]<ans) then
	  begin
	    inc(flag1[a[i]]);
	    anss[i]:=a[i];
	  end;
	end;
  end;
  i:=1;
  j:=1;
  while (j<=m) and (flag1[j]>=ans) do inc(j);
  while (i<=n) do
  begin
    if (anss[i]=0) then
	begin
	  if (j<>m+1) then 
	  begin
	  anss[i]:=j;
	  inc(flag1[j]);
	  while (j<=m) and (flag1[j]>=ans) do inc(j);
	  end else anss[i]:=a[i];
	end;
	inc(i);
  end;
  for i:=1 to n do
	write(anss[i],' ');
  writeln;
end.
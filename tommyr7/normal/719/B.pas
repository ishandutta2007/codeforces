uses math;
var n,i,j,ans,ans1,ans2:longint;
    a:array[0..100000] of longint;
	x:char;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
  begin
    read(x);
    if (x='r') then a[i]:=1;
  end;
  ans1:=0;
  ans2:=0;
  for i:=1 to n do
  begin
	if (i mod 2=1) and (a[i]=0) then inc(ans1);
	if (i mod 2=0) and (a[i]=1) then inc(ans2);
  end;
  ans:=max(ans1,ans2);
  ans1:=0;
  ans2:=0;
  for i:=1 to n do
  begin
    if (i mod 2=0) and (a[i]=0) then inc(ans1);
	if (i mod 2=1) and (a[i]=1) then inc(ans2);
  end;
  ans:=min(ans,max(ans1,ans2));
  writeln(ans);
end.
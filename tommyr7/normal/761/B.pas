var n,l,i,j,nowx:longint;
    a,b,a1,b1:array[0..1007] of longint;
	ans,flag:boolean;
begin
  readln(n,l);
  randomize;
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(a1,sizeof(a1),0);
  fillchar(b1,sizeof(b1),0);
  for i:=1 to n do
	read(a[i]);
  a1[n]:=a[1]+l-a[n];
  readln;
  for i:=1 to n do
	read(b[i]);
  b1[n]:=b[1]+l-b[n];
  for i:=1 to n-1 do
  begin
    a1[i]:=a[i+1]-a[i];
    b1[i]:=b[i+1]-b[i];
  end;
  for i:=1 to n do
	b1[i+n]:=b1[i];
  readln;
  ans:=false;
  for nowx:=0 to n do
  begin
    flag:=true;
    for i:=1 to n do
	  if (a1[i]<>b1[i+nowx]) then flag:=false;
	if flag then ans:=true;
  end;
  if ans then writeln('YES') else writeln('NO');
end.
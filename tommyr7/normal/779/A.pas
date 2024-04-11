var n,i,j,x,y,ans:longint;
    tot1,tot2:array[1..5] of longint;
begin
  readln(n);
  fillchar(tot1,sizeof(tot1),0);
  fillchar(tot2,sizeof(tot2),0);
  for i:=1 to n do
  begin
    read(x);
    inc(tot1[x]);
  end;
  readln;
  for i:=1 to n do
  begin
    read(x);
    inc(tot2[x]);
  end;
  readln;
  ans:=0;
  for i:=1 to 5 do
	if ((tot1[i]+tot2[i]) mod 2=1) then ans:=-1;
  if (ans=-1) then writeln(ans) else
  begin
    for i:=1 to 5 do
	  ans:=ans+(abs(tot2[i]-tot1[i]) div 2);
	ans:=ans div 2;
	writeln(ans);
  end;
end.
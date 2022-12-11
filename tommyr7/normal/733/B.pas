var n,i,j,sum1,sum2,t,ans:longint;
    a,b:array[0..100007] of longint;
begin
  readln(n);
  sum1:=0;sum2:=0;
  for i:=1 to n do
  begin
    readln(a[i],b[i]);
    sum1:=sum1+a[i];
    sum2:=sum2+b[i];
  end;
    t:=(sum1-sum2);
    ans:=0;
    for i:=1 to n do
		if (abs((a[i]-b[i])*2-t)>abs((a[ans]-b[ans])*2-t)) then ans:=i;
	writeln(ans);
end.
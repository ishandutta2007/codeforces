var n,i,j,k,ans:longint;
    sum,a:array[0..300] of longint;
begin
  readln(n);
  fillchar(sum,sizeof(sum),0);
  for i:=1 to n do
  begin
	read(a[i]);
    sum[i]:=sum[i-1]+a[i];
  end;
  readln;
  if (sum[n]<>0) then
  begin
    writeln('YES');
    writeln('1');
    writeln(1,' ',n);
  end
  else
  begin
    ans:=-1;
    for i:=1 to n-1 do
	  if (sum[i]<>0) then ans:=i;
	if (ans=-1) then writeln('NO') else
	begin
	  writeln('YES');
	  writeln('2');
	  writeln(1,' ',ans);
	  writeln(ans+1,' ',n);
	end;
  end;
end.
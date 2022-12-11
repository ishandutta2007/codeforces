var n,k,i,ans:longint;
    a:array[0..100005] of longint;
begin
  readln(n,k);
  fillchar(a,sizeof(a),0);
  ans:=0;
  for i:=1 to n do
	read(a[i]);
  readln;
  ans:=n;
  while (ans>1) and (a[ans]-a[ans-1]<=k) do dec(ans);
  ans:=n-ans;
  writeln(ans+1);
end.
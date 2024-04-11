var n,i,j,max:longint;
    a:array[0..200000] of longint;
	ans,tot:array[0..200000] of int64;
	anss:int64;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  fillchar(tot,sizeof(tot),0);
  fillchar(ans,sizeof(ans),0);
  max:=0;
  for i:=1 to n do
  begin
	read(a[i]);
    tot[a[i]]:=tot[a[i]]+1;
    if (a[i]>max) then max:=a[i];
  end;
  readln;
  for i:=max-1 downto 1 do
	tot[i]:=tot[i]+tot[i+1];
  for i:=1 to max do
    for j:=1 to max div i do
		ans[i]:=ans[i]+int64(tot[i*j]*i);
  anss:=0;
  for i:=1 to n do
	if (ans[a[i]]>anss) then anss:=ans[a[i]];
  writeln(anss);
end.
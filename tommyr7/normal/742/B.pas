var n,k,i,j,nowi,nowj,s,t:longint;
    a,tot,r:array[0..6000007] of longint;
	ans:int64;
begin
  readln(n,k);
  fillchar(a,sizeof(a),0);
  fillchar(tot,sizeof(tot),0);
  for i:=1 to n do
  begin
    read(a[i]);
    inc(tot[a[i]]);
  end;
  readln;
  ans:=0;
  for i:=1 to n do
    if (k xor a[i]<>a[i]) then ans:=ans+tot[k xor a[i]] else ans:=ans+tot[k xor a[i]]-1;
  writeln(ans div 2);
end.
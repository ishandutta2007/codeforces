var n,l,r,i,j:longint;
    a,p,tot,b:array[0..100007] of int64;
	now:int64;
	ans:boolean;
begin
  readln(n,l,r);
  fillchar(a,sizeof(a),0);
  fillchar(p,sizeof(p),0);
  fillchar(tot,sizeof(tot),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
	read(a[i]);
  readln;
  for i:=1 to n do
  begin
    read(p[i]);
    tot[p[i]]:=i;
  end;
  readln;
  b[tot[1]]:=l;
  now:=b[tot[1]]-a[tot[1]];
  ans:=true;
  for i:=2 to n do
  begin
    inc(now);
    b[tot[i]]:=a[tot[i]]+now;
    if (b[tot[i]]>r) then b[tot[i]]:=r;
	if (b[tot[i]]<l) then b[tot[i]]:=l;
	if (b[tot[i]]-a[tot[i]]<now) then
	begin
	  ans:=false;
	  break;
	end;
	now:=b[tot[i]]-a[tot[i]];
  end;
  if ans then
  begin
    for i:=1 to n do
	  write(b[i],' ');
	writeln;
  end else writeln(-1);
end.
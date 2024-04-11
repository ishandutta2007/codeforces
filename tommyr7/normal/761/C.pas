var n,m,i,j,k,r,ans:longint;
    s:string;
	a,b,c,d:array[0..107] of longint;
begin
  readln(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  fillchar(d,sizeof(d),0);
  for i:=1 to m do
  begin
    d[i]:=i-1;
    if (m-d[i]<d[i]) then d[i]:=m-d[i];
  end;
  for i:=1 to n do
  begin
    readln(s);a[i]:=maxlongint div 3;b[i]:=maxlongint div 3;c[i]:=maxlongint div 3;
    for r:=1 to length(s) do
	begin
	    if (ord(s[r])>=48) and (ord(s[r])<=57) and (d[r]<a[i]) then a[i]:=d[r];
	    if (ord(s[r])>=97) and (ord(s[r])<=122) and (d[r]<b[i]) then b[i]:=d[r];
	    if ((s[r]='#') or (s[r]='*') or (s[r]='&')) and (d[r]<c[i]) then c[i]:=d[r];
	end;
  end;
  ans:=maxlongint;
  for i:=1 to n do
	for j:=1 to n do
	  for k:=1 to n do
		if (i<>j) and (j<>k) and (k<>i) then
		begin
	      if (a[i]+b[j]+c[k]<ans) then ans:=a[i]+b[j]+c[k];
		end;
  writeln(ans);
end.
var n,m,i,j,k,l,now:longint;
    s:string;
	x:char;
	na,ans:array[0..3000] of string;
	vis:array[0..300] of boolean;
	r:array[0..300] of longint;
begin
  readln(n,m);
  now:=0;
  x:='A';
  for i:=1 to 52 do
  begin
    na[i]:=x;
    if (i mod 2=1) then na[i]:=na[i]+'a' else na[i]:=na[i]+'b';
	if (i mod 2=0) then x:=chr(ord(x)+1);
  end;
  for i:=1 to n-m do
  begin
    s:='';
    read(x);
    while (x<>' ') do
	begin
	  s:=s+x;
	  read(x);
	end;
	if (s='NO') then r[i]:=0 else r[i]:=1;
  end;
  readln(s);
  if (s='NO') then r[n-m+1]:=0 else r[n-m+1]:=1;
  now:=0;
  if (r[1]=0) then
  begin
    now:=1;ans[1]:=na[1];ans[2]:=na[1];
  end else
  begin
    now:=2;ans[1]:=na[1];ans[2]:=na[2];
  end;
  for i:=3 to m do
  begin
    inc(now);ans[i]:=na[now];
  end;
  for i:=m+1 to n do
	if (r[i-m+1]=0) then ans[i]:=ans[i-m+1] else
	begin
	  inc(now);ans[i]:=na[now];
	end;
  for i:=1 to n do
	write(ans[i],' ');
  writeln;
end.
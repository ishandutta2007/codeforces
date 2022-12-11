var n,i,j,anss,s1,s2,s3:longint;
    f,ans:array[1..5000] of longint;
begin
  readln(n);
  if (n div 2=1) then
  begin
    fillchar(f,sizeof(f),0);
    for i:=1 to n-1 do
	begin
	  writeln('? ',i,' ',i+1);
	  flush(output);
	  readln(f[i]);
	end;
	writeln('? ',n,' ',1);
	flush(output);
	readln(f[n]);
	anss:=0;
	for i:=1 to n do
		anss:=anss+f[i];
	anss:=anss div 2;
	fillchar(ans,sizeof(ans),0);
	ans[1]:=anss;
	i:=2;
	while (i<=n) do
	begin
	  ans[1]:=ans[1]-f[i];
	  i:=i+2;
	end;
	for i:=1 to n-1 do
		ans[i+1]:=f[i]-ans[i];
	write('! ');
	for i:=1 to n do
		write(ans[i],' ');
	writeln;
	flush(output);
  end
  else
  begin
    writeln('? 1 2');
    flush(output);
    readln(s1);
    writeln('? 2 3');
    flush(output);
    readln(s2);
    writeln('? 3 1');
    flush(output);
    readln(s3);
    fillchar(ans,sizeof(ans),0);
    ans[1]:=(s1+s3-s2) div 2;
    ans[2]:=s1-ans[1];
    ans[3]:=s2-ans[2];
    for i:=3 to n-1 do
	begin
	  writeln('? ',i,' ',i+1);
	  readln(s1);
	  ans[i+1]:=s1-ans[i];
	end;
	write('! ');
	for i:=1 to n do
	  write(ans[i],' ');
	writeln;
	flush(output);
  end;
end.
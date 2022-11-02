var
  j,ans,n,i:longint;
  s1,s2:ansistring;

begin
  readln(n);
  readln(s1);
  ans:=length(s1);
  for i:=2 to n do begin
    readln(s2);
    j:=1;
    while (j<=length(s1))and(j<=length(s2))and(s1[j]=s2[j])do inc(j);
    dec(j);
    if (j<ans)then ans:=j;
    s1:=s2;
  end;
  writeln(ans);
end.
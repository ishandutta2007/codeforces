const
  a:array [1..20] of longint = (1,2,3,5,8,13,21,30,39,53,74,95,128,152,182,212,258,316,374,413);

var
  n,i,j:longint;

begin
  read(n);
  for i:=1 to n do begin
    for j:=1 to n do 
      if (i=j)then write(0, ' ') else write(a[i]+a[j],' ');
    writeln;
  end;
end.
{$r-,q-,s-,i-,o+}
var
  ans,n,i,x,res:longint;
  rev,a,mm:array[0..2000500]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do begin
    read(x);
    rev[x]:=i;
  end;
  for i:=1 to n do a[i]:=n-rev[a[i]]+1;
  fillchar(mm,sizeof(mm),$0);
  ans:=1;
  for i:=1 to n do begin
    x:=a[i]-1;
    res:=0;
    while (x>0)do begin
      if (mm[x]>res)then res:=mm[x];
      x:=x and (x-1);
    end;
    if (res+1>ans)then ans:=res+1;
    inc(res);
    x:=a[i];
    while (x<=n)do begin
      if (res>mm[x])then mm[x]:=res;
      x:=x or (x-1)+1;
    end;
  end;
  writeln(ans);
end.
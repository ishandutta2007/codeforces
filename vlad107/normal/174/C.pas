var
  n,kt,i,j:longint;
  t1,t2,last,a:array[0..500500]of longint;
  
  procedure add(x,y:longint);
    begin
      inc(kt);
      t1[kt]:=x;
      t2[kt]:=y;
    end;

begin
  read(n);
  a[0]:=0;
  a[n+1]:=0;
  kt:=0;
  for i:=1 to n+1 do begin
    if (i<=n)then read(a[i]);
    if (a[i]>a[i-1])
      then for j:=a[i-1]+1 to a[i] do last[j]:=i
      else for j:=a[i]+1 to a[i-1] do add(last[j],i-1);
  end;
  writeln(kt);
  for i:=1 to kt do writeln(t1[i],' ',t2[i]);
end.
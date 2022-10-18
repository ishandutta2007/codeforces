const
  inf=10000;

var
  n,k,m,i:longint;
  t,ans:array[0..100000]of longint;

begin
  read(n);
  t[0]:=-inf;
  ans[0]:=0;
  k:=0;
  m:=0;
  for i:=1 to n do
    begin
      read(t[i]);
      while t[k+1]<=t[i]-90 do
        inc(k);
      while t[m+1]<=t[i]-1440 do
        inc(m);
      if ans[k]+50<ans[m]+120
        then ans[i]:=ans[k]+50
        else ans[i]:=ans[m]+120;
      if ans[i]>ans[i-1]+20 then
        ans[i]:=ans[i-1]+20;
      writeln(ans[i]-ans[i-1])
    end
end.
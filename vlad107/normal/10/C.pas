{$r-,q-,s-,i-,o+}
const
  maxn=1000100;
var
  n,i,sum,x,y:longint;
  res:int64;
  d:array[0..maxn+10]of longint;
  kd:array[0..10]of longint;
begin
  read(n);
  for i:=1 to 9 do d[i]:=i;
  for i:=10 to maxn do begin
    x:=i;
    sum:=0;
    while (x>0)do begin
      sum:=sum+(x mod 10);
      x:=x div 10;
    end;
    d[i]:=d[sum];
  end;
  fillchar(kd,sizeof(kd),$0);
  for i:=1 to n do inc(kd[d[i]]);
  res:=0;
  for x:=1 to 9 do
    for y:=1 to 9 do
      res:=res+int64(kd[d[x*y]])*kd[x]*kd[y];
  for i:=1 to n do
    res:=res-(n div i);
  writeln(res);
end.
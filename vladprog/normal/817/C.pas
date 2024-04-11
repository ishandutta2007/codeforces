function sum(x:int64):int64;
var
  i:longint;
  k:int64;
  s:string;
begin
  str(x,s);
  k:=0;
  for i:=1 to length(s) do
    inc(k,ord(s[i])-48);
    sum:=k
end;

var
  l,r,m,n,s:int64;

begin
  read(n,s);
  l:=1;
  r:=n+1;
  while r-l>1 do
    begin
      m:=(l+r)div 2;
      if m-sum(m)>=s
        then r:=m
        else l:=m
    end;
  writeln(n-r+1)
end.
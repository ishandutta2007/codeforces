{$r-,q-,s-,i-,o+}
const
  sr=18500;
  ksr=100500;

var
  ss,ff,kp,res,l,r,i,q,j,ll,rr,tx:longint;
  prime:array[0..500500]of boolean;
  p:array[0..500500]of longint;

begin
  read(l,r);
  fillchar(prime,sizeof(prime),true);
  prime[1]:=false;
  kp:=0;
  for i:=2 to sr do 
    if (prime[i])then begin
      inc(kp);
      p[kp]:=i;
      for j:=2 to sr div i do prime[i*j]:=false;
    end;
  fillchar(prime,sizeof(prime),true);
  i:=1;
  res:=0;
  while (i<=r)do begin
    ll:=i;rr:=i+ksr-1;
    for q:=1 to kp do begin
      tx:=p[q];
      ss:=ll div tx;
      ff:=rr div tx;
      if (tx*ss<>ll)then inc(ss);
      if (ss<2)then ss:=2;
      for j:=ss to ff do prime[tx*j-ll+1]:=false;
    end;
    if (i=1)then prime[1]:=false;
    for q:=1 to ksr do begin
      if (prime[q])and(((q+ll-2) and 3=0)or(q+ll-1=2))and(q+ll-1>=l)and(q+ll-1<=r)then inc(res);
      prime[q]:=true;
    end;
    inc(i,ksr);
  end;
  writeln(res);
end.
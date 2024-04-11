{$r-,q-,s-,i-,o+}
const
  maxn=10000010;
  maxans:int64=9999998000005;

var
  m,cm:int64;
  d,j,n,i,x:longint;
  ca,p:array[0..maxn+10]of longint;
  kol:array[0..maxn+10]of int64;
  a:array[0..1000500]of longint;
  
  function calc(x,t:int64):int64;
    var
      res:int64;
    begin
      res:=0;
      while (x>0)do begin
        x:=x div t;
        res:=res+x;
      end;
      calc:=res;
    end;
  
  function find(x,t:int64):int64;
    var
      mid,ll,rr:int64;
    begin
      ll:=1;rr:=maxans;
      while (ll<rr-1)do begin
        mid:=(ll+rr)shr 1;
        if (calc(mid,x)>=t)
          then rr:=mid
          else ll:=mid;
      end;
      if (Calc(ll,x)>=t)then find:=ll else find:=rr;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to maxn do begin
    p[i]:=i;
    kol[i]:=0;
    ca[i]:=0;
  end;
  for i:=2 to maxn do begin
    if (i*i>maxn)then break;
    if (p[i]=i)then 
      for j:=i to maxn div i do p[i*j]:=i;
  end;
  for i:=1 to n do inc(ca[a[i]]);
  d:=n;
  for i:=1 to maxn do begin
    if (d=0)then break;
    x:=i;
    while (x>1)do begin
      inc(kol[p[x]],d);
      x:=x div p[x];
    end;
    dec(d,ca[i]);
  end;
  m:=1;
  for i:=1 to maxn do
    if (kol[i]<>0)then begin
      cm:=find(i,kol[i]);
      if (cm>m)then m:=cm;
    end;
  writeln(m);
end.
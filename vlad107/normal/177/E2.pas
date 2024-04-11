{$r-,q-,s-,i-,o+}
const
  inf=2000000000000000000;

var
  a,b:array[0..500500]of int64;
  c,i,n:longint;
  maxr,ll,rr,mid,lll:int64;
  
  function find(x:int64):int64;
    var
      sum:int64;
    
    begin
      sum:=0;
      for i:=1 to n do begin
        sum:=sum+x*a[i] div b[i];
        if (sum>c)then break;
      end;
      find:=sum;
    end;

begin
  read(n,c);
  for i:=1 to n do read(a[i],b[i]);
  i:=1;
  while (i<=n)and(a[i]=0)do inc(i);
  if (i>n)or(c<n)then begin
    if (c=n)then writeln(-1)else writeln(0);
    exit;
  end;
  dec(c,n);

  ll:=1;
  rr:=2;
  for i:=1 to n do 
    if (a[i]<>0)and(inf div a[i]+1>rr)then rr:=inf div a[i]+1;
  maxr:=rr;
  while (ll<rr-1)do begin
    mid:=(ll+rr)div 2;
    if (find(mid)>=c)then rr:=mid else ll:=mid;
  end;
  if (find(ll)<>c)and(find(rr)<>c)then begin
    writeln(0);
    exit;
  end;
  if (find(ll)=c)then lll:=ll else lll:=rr;
  rr:=maxr;
  while (ll<rr-1)do begin
    mid:=(ll+rr)div 2;
    if (find(mid)>c)then rr:=mid else ll:=mid;
  end;
  if (find(rr)=c)
    then writeln(rr-lll+1)
    else writeln(ll-lll+1);
end.

const
  maxn=1000000;

var
  n:int64;
  max,j,qqq,first,last,res,tt,i:longint;
  used,f:array[0..maxn]of longint;
  sf:array[0..maxn,0..5]of longint;
  
  function find1(n:int64):longint;
    var
      ll,rr,mm:longint;
      
    begin
      ll:=0;rr:=trunc(sqrt(n))+10;
      while (ll<rr-1)do begin
        mm:=(ll+rr)shr 1;
        if (int64(mm)*mm>n)then rr:=mm else ll:=mm;
      end;
      if (int64(rr)*rr<=n)then find1:=rr else find1:=ll;    
    end;
    
  function find2(n:int64):longint;
    var
      ll,rr,mm:longint;
      
    begin
      ll:=0;rr:=trunc(sqrt(trunc(sqrt(n))+100))+100;
      while (ll<rr-1)do begin
        mm:=(ll+rr)shr 1;
        if (int64(mm)*mm*mm*mm<=n)then ll:=mm else rr:=mm;
      end;
      if (int64(ll)*ll*ll*ll>=n)then find2:=ll else find2:=rr;
    end;

begin
  //assign(input,'1.in');reset(input);
  //assign(output,'1.out');rewrite(output);
  f[0]:=0;
  sf[0][0]:=1;
  res:=0;
  qqq:=0;
  for i:=1 to maxn do begin
    f[i]:=0;
    if (i>=4)then f[i]:=1;
    if (i>=16)then f[i]:=2;
    if (i>=82)then f[i]:=0;
    if (i>=6724)then f[i]:=3;
    if (i>=50626)then f[i]:=1;
    
    sf[i]:=sf[i-1];
    inc(sf[i][f[i]]);
  end;
  
  
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(n);
    
    first:=find2(n);
    last:=find1(n);
    if (last>=n)then last:=n-1;
    i:=0;
    while (sf[last][i]-sf[first-1][i]<>0)do inc(i);
    res:=res xor i;
  end;
  if (res=0)then writeln('Rublo')else writeln('Furlo');
end.
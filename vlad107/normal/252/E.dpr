{$r-,q-,s-,i-,o+}
var
  res,left,right,qt,a,b:int64;
  j,bx,k,t,i:longint;
  g,f:array[0..1111111]of int64;
  
  function gcd(x,y:longint):longint;
    begin
      while (x<>0)and(y<>0)do
        if (x>y)then x:=x mod y else y:=y mod x;
      gcd:=x+y;
    end;

begin
  read(a,b,k);
  t:=1;
  for i:=2 to k do t:=t*i div gcd(t,i);
  f[0]:=0;
  for i:=1 to t do begin
    f[i]:=f[i-1]+1;
    for j:=2 to k do 
      if (i mod j<>0)and(f[i-(i mod j)]+1<f[i])then f[i]:=f[i-(i mod j)]+1;
  end;
  bx:=b mod t;
  if (bx=0)then bx:=t;
  for i:=0 to bx-1 do g[i]:=1000000000;
  g[bx]:=0;
  for i:=bx+1 to t do begin
    g[i]:=g[i-1]+1;
    for j:=2 to k do 
      if (i mod j<>0)and(g[i-(i mod j)]+1<g[i])then g[i]:=g[i-(i mod j)]+1;
  end;
  res:=f[a mod t]+g[t];
  right:=a div t;
  left:=(b+t-1) div t;
  if (left-1=right)then begin
    writeln(g[a mod t]);
    exit;
  end;
  qt:=right-left;
  res:=res+qt*f[t];
  writeln(res);
end.
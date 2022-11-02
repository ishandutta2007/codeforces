const
  inf=2000000000;

var
  s,a,f:array[0..500500]of longint;
  n,t,x,i,j:longint;
  
  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;
      
    begin
      i:=l;j:=r;
      xx:=a[i+random(j-i+1)];
      while (i<=j)do begin
        while (a[i]>xx)do inc(i);
        while (a[j]<xx)do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  randomize;
  read(n);
  t:=inf;
  for i:=1 to n do begin
    read(x);
    if (x<t)then t:=x;
  end;
  read(n);
  for i:=1 to n do read(a[i]);
  qs(1,n);
  s[0]:=0;
  for i:=1 to n do s[i]:=s[i-1]+a[i];
  f[0]:=0;
  for i:=1 to n do f[i]:=inf;
  for i:=0 to n-1 do begin
    if (f[i]+a[i+1]<f[i+1])then f[i+1]:=f[i]+a[i+1];
    j:=i+t;
    if (j<=n)and(f[i]+s[i+t]-s[i]<f[j])then f[j]:=f[i]+s[i+t]-s[i];
    j:=i+t+1;
    if (j<=n)and(f[i]+s[i+t]-s[i]<f[j])then f[j]:=f[i]+s[i+t]-s[i];
    j:=i+t+2;
    if (j<=n)and(f[i]+s[i+t]-s[i]<f[j])then f[j]:=f[i]+s[i+t]-s[i];    
  end;
  writeln(f[n]);
end.
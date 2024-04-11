uses
  math;
  
var
  s,p:ansistring;
  max,k,q,lz,rz,j,i,n:longint;
  u,v,t,f,pf,z:array[0..500500]of longint;

begin
  readln(s);
  n:=length(s);
  p:='';
  for i:=1 to n do p:=p+s[n-i+1];
  z[1]:=0;j:=0;
  for i:=2 to n do begin
    while (j>0)and(p[i]<>p[j+1])do j:=z[j];
    if (p[j+1]=p[i])then inc(j);
    z[i]:=j;
  end;
  j:=0;
  for i:=1 to n do begin
    while (j>0)and(s[i]<>p[j+1])do j:=z[j];
    if (p[j+1]=s[i])then inc(j);
    f[i]:=j;
  end;
  pf[1]:=1;
  for i:=2 to n do begin
    pf[i]:=i;
    if (f[i-1]>f[i])then begin
      f[i]:=f[i-1];
      pf[i]:=pf[i-1];
    end;
  end;
  t[1]:=1;lz:=1;rz:=1;
  max:=1;k:=1;u[1]:=1;v[1]:=1;
  for i:=2 to n do begin
    if (rz>=i)then j:=min(rz-i+1,t[lz-(i-lz)]) else j:=1;
    while (i-j>=1)and(i+j<=n)and(s[i-j]=s[i+j])do inc(j);
    if (i+j-1>rz)then begin lz:=i;rz:=i+j-1; end;
    t[i]:=j;
    if (2*j-1>max)then begin
      max:=2*j-1;
      k:=1;u[1]:=i-j+1;v[1]:=max;
    end;
    q:=min(f[i-j],n-(i+j-1));
    if (q<>0)and(2*j-1+2*q>max)then begin
      max:=2*j-1+2*q;
      k:=3;
      u[1]:=pf[i-j]-q+1;v[1]:=q;
      u[2]:=i-j+1;v[2]:=2*j-1;
      u[3]:=n-q+1;v[3]:=q;
    end;
  end;
  writeln(k);
  for i:=1 to k do writeln(u[i],' ',v[i]);
end.
{$r-,q-,s-,i-,o+}
const
  maxn=800500;
  ABC='aeiouAEIOU';
  inf=1000000000;

var
  s:ansistring;
  cr,x,n,i,max,kmax:longint;
  a,fmin:array[0..2*maxn]of longint;

begin
  readln(s);
  n:=length(s);

  a[0]:=0;
  for i:=1 to n do begin
    if (pos(s[i],ABC)>0)
      then a[i]:=-1
      else a[i]:=2;
    a[i]:=a[i-1]+a[i];
  end;
  for i:=1 to n do a[i]:=a[i]+maxn div 2;

  for i:=1 to maxn do fmin[i]:=inf;
  max:=0;kmax:=0;
  for i:=1 to n do begin
    x:=a[i];
    while (x<=maxn)do begin
      if (i<fmin[x])then fmin[x]:=i;
      x:=x or (x-1)+1;
    end;
    x:=a[i];
    cr:=inf;
    while (x>0)do begin
      if (fmin[x]<cr)then cr:=fmin[x];
      x:=x and (x-1);
    end;
    if (a[i]>=maxn div 2)then cr:=0;
    if (i-cr>max)then begin
      max:=i-cr;
      kmax:=0;
    end;
    if (i-cr=max)then inc(kmax);
  end;
  if (max=0)
    then writeln('No solution')
    else writeln(max,' ',kmax);
end.
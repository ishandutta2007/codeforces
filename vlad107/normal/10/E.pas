
{$r-,q-,s-,i-,o+}
const
  inf=maxlongint;

var
  c,m,g:array[0..500500]of longint;
  k,n,i,j:longint;
  bad:boolean;
  c1,c2,min,x,w,ww:longint;

begin
  read(n);
  for i:=1 to n do read(c[i]);
  min:=inf;
  for i:=2 to n do
    for j:=i to n do begin
      x:=c[i-1]-1;
      for k:=1 to n do m[k]:=0;
      for k:=1 to n do begin
        m[k]:=x div c[k];
        x:=x-m[k]*c[k];
      end;
      for k:=j+1 to n do m[k]:=0;
      inc(m[j]);
      w:=0;
      for k:=1 to n do w:=w+m[k]*c[k];
      ww:=w;
      for k:=1 to n do begin
        g[k]:=w div c[k];
        w:=w-g[k]*c[k];
      end;
      bad:=false;
      for k:=1 to n do
        if (g[k]<>m[k])then begin
          bad:=true;
          break;
        end;
      if (not bad)then continue;
      c1:=0;c2:=0;
      for k:=1 to n do begin
        c1:=c1+m[k];
        c2:=c2+g[k];
      end;
      if (c1>=c2)then continue;
      if (ww<min)then min:=ww;
    end;
  if (min=inf)then min:=-1;
  writeln(Min);
end.
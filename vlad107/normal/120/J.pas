{$r-,q-,s-,i-,o+}
uses
  math;
const
  al=pi/17;
  kit=500;
  inf=1000000000;
var
  z,nom:array[0..500500]of longint;
  x,y:array[0..500500]of extended;
  tmp,i,j,n,n1,n2:longint;
  tt,res,ug,r,d:extended;
  procedure qs(l,r:longint);
    var
      nn,i,j:longint;
      xx,yy:extended;
      tt:extended;
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=x[nn];
      yy:=y[nn];
      while (i<=j)do begin
        while (xx>x[i])or(xx=x[i])and(yy>y[i])do inc(i);
        while (xx<x[j])or(xx=x[j])and(yy<y[j])do dec(j);
        if (i>j)then break;
        tt:=x[i];x[i]:=x[j];x[j]:=tt;
        tt:=y[i];y[i]:=y[j];y[j]:=tt;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  randomize;
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do begin
    read(x[i],y[i]);
    if (x[i]<0)and(y[i]<0)then z[i]:=4 else
    if (x[i]<0)then z[i]:=2 else
    if (y[i]<0)then z[i]:=3 else
    z[i]:=1;
    x[i]:=abs(x[i]);
    y[i]:=abs(y[i]);
    nom[i]:=i;
  end;
  for i:=1 to n do begin
    if (x[i]=0)and(y[i]=0)then continue;
    r:=sqrt(x[i]*x[i]+y[i]*y[i]);
    ug:=arctan2(y[i],x[i]);
    ug:=ug+al;
    x[i]:=r*sin(ug);
    y[i]:=r*cos(ug);
  end;

  n1:=0;n2:=0;
  res:=inf;
  qs(1,n);
  for i:=1 to n do
    for j:=i-1 downto i-kit do begin
      if (j<1)then break;
      d:=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      if (d<res)then begin
        res:=d;n1:=nom[i];n2:=nom[j];
      end;
    end;

  for i:=1 to n do tt:=x[i];x[i]:=y[i];y[i]:=tt;
  qs(1,n);

  for i:=1 to n do
    for j:=i-1 downto i-kit do begin
      if (j<1)then break;
      d:=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      if (d<res)then begin
        res:=d;n1:=nom[i];n2:=nom[j];
      end;
    end;

  if (z[n2]=4)then z[n2]:=1 else
  if (z[n2]=1)then z[n2]:=4 else
  if (z[n2]=2)then z[n2]:=3 else
  z[n2]:=2;
  writeln(n1,' ',z[n1],' ',n2,' ',z[n2]);
  close(output);close(input);
end.
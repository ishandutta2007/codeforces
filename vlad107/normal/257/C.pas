{$r-,q-,s-,i-,o+}
uses
  math;
const
  eps=1e-12;

var
  t,ans:extended;
  a:array[0..500500]of extended;
  kp,j,n,i:longint;
  x,y:array[0..500500]of longint;
  
  procedure qs(l,r:longint);
    var
      i,j:longint;
      xx,tmp:extended;
      
    begin
      i:=l;j:=r;
      xx:=a[l+random(r-l+1)];
      while (i<=j)do begin
        while (xx>a[i]+eps)do inc(i);
        while (xx+eps<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  
  function angle(x,y:longint):extended;
    begin
      if (x=0)then begin
        if (y>0)then angle:=pi/2 else angle:=3*pi/2;
        exit;
      end;
      if (y=0)then begin
        if (x>0)then angle:=0 else angle:=pi;
        exit;
      end;
      if (x>0)and(y>0)then begin
        angle:=arctan(y/x);
        exit;
      end;
      if (x<0)and(y>0)then begin
        angle:=pi/2+arctan(-x/y);
        exit;
      end;
      if (x<0)and(y<0)then begin
        angle:=pi+arctan(y/x);
        exit;
      end;
      if (x>0)and(y<0)then begin
        angle:=3*pi/2+arctan(-x/y);
      end;
    end;

begin
  randseed:=52345;
  read(n);
  for i:=1 to n do begin
    read(x[i],y[i]);
    a[i]:=angle(x[i],y[i]);
  end;
  ans:=1e9;
  qs(1,n);
  kp:=0;
  for i:=1 to n do begin
    j:=i+1;
    if (j>n)then j:=1;
    t:=a[i]-a[j];
    if (abs(t)<eps)then begin
      inc(kp);
      continue;
    end;
    if (t<-eps)then t:=t+2*pi;
    if (t<ans)then ans:=t;
  end;
  if (kp=n)then ans:=0;
  ans:=ans*180/pi;
  writeln(ans:0:15);
end.
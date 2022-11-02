const
  eps=1e-10;
var
  found:boolean;
  i,n,j,t2:longint;
  vv1,vv2,tt,tmp,time,t:extended;
  res,x,v,m:array[0..100500]of extended;
  nom:array[0..100500]of longint;

begin
  read(n,t);
  for i:=1 to n do read(x[i],v[i],m[i]);
  for i:=1 to n do nom[i]:=i;
  for i:=1 to n-1 do 
    for j:=1 to n-1 do
      if (x[j]>x[j+1])then begin
        tmp:=x[j];x[j]:=x[j+1];x[j+1]:=tmp;
        tmp:=v[j];v[j]:=v[j+1];v[j+1]:=tmp;
        tmp:=m[j];m[j]:=m[j+1];m[j+1]:=tmp;
        t2:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=t2;
      end;
  while (true)do begin
    time:=1e9;
    for i:=1 to n-1 do 
      for j:=i+1 to i+2 do 
        if (abs(v[i]-v[j])>eps)then begin
          tt:=(x[j]-x[i])/(v[i]-v[j]);
          if (tt<eps)then continue;
          if (tt<time)then time:=tt;
        end;
    tt:=time;
    if (tt>t)then break;
    t:=t-tt;
    for i:=1 to n do x[i]:=x[i]+v[i]*tt;
    found:=true;
    while (found)do begin
      found:=false;
      for i:=1 to n-1 do 
        if (x[i]-x[i+1]<-eps)then begin
          tmp:=m[i];m[i]:=m[i+1];m[i+1]:=tmp;
          t2:=nom[i];nom[i]:=nom[i+1];nom[i+1]:=t2;
          tmp:=x[i];x[i]:=x[i+1];x[i+1]:=tmp;
          tmp:=v[i];v[i]:=v[i+1];v[i+1]:=tmp;
          found:=true;
        end;
    end;
    for i:=1 to n-1 do begin
      j:=i+1;
      if (abs(x[i]-x[j])<eps)then begin
        vv1:=v[i];
        vv2:=v[j];
        v[i]:=((m[i]-m[j])*vv1+2*m[j]*vv2)/(m[i]+m[j]);
        v[j]:=((m[j]-m[i])*vv2+2*m[i]*vv1)/(m[i]+m[j]);
      end;
    end;
  end;
  for i:=1 to n do x[i]:=x[i]+v[i]*t;
  for i:=1 to n do res[nom[i]]:=x[i];
  for i:=1 to n do writeln(res[i]:0:8,' ');
end.
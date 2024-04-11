const
  eps=1e-12;
var
  tt,tx,ty,tz,vs,vp,px,py,pz,ll,rr,mid:extended;
  x,y,z:array[0..100500]of extended;
  iii,i,n:longint;
  function dist(x1,y1,z1,x2,y2,z2:extended):extended;
    begin
      dist:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
    end;

begin
  read(n);
  inc(n);
  for i:=1 to n do read(x[i],y[i],z[i]);
  read(vp,vs);
  read(px,py,pz);
  rr:=0;
  for i:=1 to n-1 do 
    rr:=rr+dist(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1])/vs;
  ll:=0;
  if (rr-dist(x[n],y[n],z[n],px,py,pz)/vp<-eps)
    then begin
      writeln('NO');
      exit;
    end;
  for iii:=1 to 550 do begin
    mid:=(ll+rr)/2;
    for i:=1 to n-1 do begin
      tt:=dist(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1])/vs;
      if (mid-tt>eps)
        then mid:=mid-tt
        else begin
          tx:=x[i]+(x[i+1]-x[i])*mid/tt;
          ty:=y[i]+(y[i+1]-y[i])*mid/tt;
          tz:=z[i]+(z[i+1]-z[i])*mid/tt;
          break;
        end;
    end;
    if ((ll+rr)/2-dist(tx,ty,tz,px,py,pz)/vp<-eps)
      then ll:=(ll+rr)/2
      else rr:=(ll+rr)/2;
  end;
  writeln('YES');
  writeln((ll+rr)/2:0:10);
  writeln(tx:0:10,' ',ty:0:10,' ',tz:0:10);
end.
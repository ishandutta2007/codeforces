var
  mx,my,mz,max,coef,tx,ty,tz:extended;
  x,y,z:array[0..500500]of extended;
  n,i,it:longint;
  
  function dist(x1,y1,z1,x2,y2,z2:extended):extended;
    begin
      dist:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
    end;

begin
  read(n);
  for i:=1 to n do read(x[i],y[i],z[i]);
  tx:=0;ty:=0;tz:=0;
  for i:=1 to n do begin
    tx:=tx+x[i];
    ty:=ty+y[i];
    tz:=tz+z[i];
  end;
  tx:=tx/n;
  ty:=ty/n;
  tz:=tz/n;
  coef:=0.9999999;
  for it:=1 to 100000 do begin
    max:=0;
    for i:=1 to n do 
      if (dist(x[i],y[i],z[i],tx,ty,tz)>max)then begin
        max:=dist(x[i],y[i],z[i],tx,ty,tz);
        mx:=x[i];my:=y[i];mz:=z[i];
      end;
    tx:=tx+(mx-tx)*coef;
    ty:=ty+(my-ty)*coef;
    tz:=tz+(mz-tz)*coef;
    coef:=coef*0.999;
  end;
  writeln(tx:0:10,' ',ty:0:10,' ',tz:0:10);
end.
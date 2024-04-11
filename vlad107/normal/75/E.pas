{$r-,q-,s-,i-,o+}
const
  eps=1e-10;
var
  t,n1,n2,ka,n,i,j:longint;
  x0,y0,x,y:array[0..500]of extended;
  nn:array[0..500]of longint;
  kx,ky,px,py,cr,dd,res,tmp,sx,sy,ex,ey,sumdist:extended;
  function dist(x1,y1,x2,y2:extended):extended;
    begin
      dist:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    end;
  procedure line(x1,y1,x2,y2:extended;var a,b,c:extended);
    begin
      a:=y2-y1;
      b:=x1-x2;
      c:=-a*x1-b*y1;
    end;
  procedure perp(x,y,a,b,c:extended;var a2,b2,c2:extended);
    begin
      a2:=-b;
      b2:=a;
      c2:=-a2*x-b2*y; 
    end;
  procedure cross(a1,b1,c1,a2,b2,c2:extended;var x,y:extended);
    var
      d,dx,dy:extended;
    begin
      d:=-a1*b2+b1*a2;
      if (abs(d)<eps)then begin
        x:=1e9;
        exit;
      end;
      dy:=a1*c2-c1*a2;
      dx:=c1*b2-b1*c2;
      x:=dx/d;
      y:=dy/d;
    end;
  procedure sol(sx,sy,ex,ey:extended);
    var
      j,i:longint;
      xx,yy,a,b,c,a2,b2,c2:extended;
    begin
      line(sx,sy,ex,ey,a,b,c);
      ka:=0;
      for i:=1 to n do begin
        line(x[i],y[i],x[i+1],y[i+1],a2,b2,c2);
        cross(a2,b2,c2,a,b,c,xx,yy);
        if (xx=1e9)then continue;
        if (abs(dist(x[i],y[i],xx,yy)+dist(xx,yy,x[i+1],y[i+1])-dist(x[i],y[i],x[i+1],y[i+1]))<eps)and
           (abs(dist(sx,sy,xx,yy)+dist(xx,yy,ex,ey)-dist(sx,sy,ex,ey))<eps)
             then begin
               j:=1;
               while (j<=ka)do begin
                 if (abs(x0[j]-xx)<eps)and(abs(y0[j]-yy)<eps)then break;
                 inc(j);
               end;
               if (j>ka)then begin
                 inc(ka);
                 x0[ka]:=xx;
                 y0[ka]:=yy;
                 nn[ka]:=i;
               end;
             end;
      end;
    end;
  procedure find(sx,sy,x1,y1,x2,y2:extended;var kx,ky:extended;var n1:longint);
    var
      a2,b2,c2,a3,b3,c3,xx,yy:extended;
    begin
      kx:=1e9;ky:=1e9;
      sol(sx,sy,x1,y1);
      if (ka=1)then begin
        kx:=x1;ky:=y1;n1:=nn[1];
      end;
      sol(sx,sy,x2,y2);
      if (ka=1)and(dist(sx,sy,kx,ky)>dist(sx,sy,x2,y2))
        then begin
          kx:=x2;ky:=y2;n1:=nn[1];
        end;
      line(x1,y1,x2,y2,a2,b2,c2);
      perp(sx,sy,a2,b2,c2,a3,b3,c3);
      cross(a2,b2,c2,a3,b3,c3,xx,yy);
      if (abs(dist(x1,y1,xx,yy)+dist(x2,y2,xx,yy)-dist(x1,y1,x2,y2))<eps)then begin
        sol(sx,sy,xx,yy);
        if (ka=1)and(dist(sx,sy,kx,ky)>dist(sx,sy,xx,yy))
          then begin
            kx:=xx;ky:=yy;n1:=nn[1];
          end;
      end;
    end;    
begin
  read(sx,sy,ex,ey,n);
  for i:=1 to n do read(x[i],y[i]);
  x[n+1]:=x[1];y[n+1]:=y[1];
//  sol(ex,ey,3,12);
//  writeln(ka);//test
  sumdist:=0;
  for i:=1 to n do sumdist:=sumdist+dist(x[i],y[i],x[i+1],y[i+1]);
  sol(sx,sy,ex,ey);
  if (ka<2)then begin
    writeln(dist(sx,sy,ex,ey):0:8);
    exit;
  end;
  res:=2*dist(x0[1],y0[1],x0[2],y0[2]);
  if (dist(x0[1],y0[1],sx,sy)>dist(x0[2],y0[2],sx,sy))
    then begin
      tmp:=x0[1];x0[1]:=x0[2];x0[2]:=tmp;
      tmp:=y0[1];y0[1]:=y0[2];y0[2]:=tmp;
      i:=nn[1];nn[1]:=nn[2];nn[2]:=i;
    end;
  res:=res+dist(sx,sy,x0[1],y0[1])+dist(x0[2],y0[2],ex,ey);
  kx:=x0[1];ky:=y0[1];n1:=nn[1];
  px:=x0[2];py:=y0[2];n2:=nn[2];
  cr:=dist(sx,sy,x0[1],y0[1])+dist(ex,ey,x0[2],y0[2]);
  dd:=dist(kx,ky,x[n1+1],y[n1+1])+dist(x[n2],y[n2],px,py);
  t:=n1+1;
  if (t>n)then t:=1;
  while (t<>n2)do begin
    dd:=dd+dist(x[t],y[t],x[t+1],y[t+1]);
    inc(t);
    if (t>n)then t:=1;
  end;
  if (sumdist-dd<dd)then dd:=sumdist-dd;
  if (cr+dd<res)then res:=cr+dd;
  writeln(res:0:8);
end.
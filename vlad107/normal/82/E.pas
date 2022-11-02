{$r-,q-,s-,i-,o+}
const
  eps=1e-6;
var
  kh3,j,t,kh,kh2,n,h,f,i:longint;
  ss,a2,b2,c2,xx,yy,a,b,c,res:extended;
  x3,y3,x,y,x1,y1,x2,y2,l,r,lx,rx:array[0..1111]of extended;
  procedure line(x1,y1,x2,y2:extended;var a,b,c:extended);
    begin
      a:=y2-y1;
      b:=x1-x2;
      c:=-a*x1-b*y1;
    end;
  function sq(x,y,a,b,c:extended):extended;
    begin
      sq:=a*x+b*y+c;
    end;
  function cross(a1,b1,c1,a2,b2,c2:extended;var x,y:extended):extended;
    var
      d,dx,dy:extended;
    begin
      d:=-a1*b2+b1*a2;
      dx:=c1*b2-b1*c2;
      dy:=a1*c2-c1*a2;
      x:=dx/d;
      y:=dy/d;
    end;
  function dist(x1,y1,x2,y2:extended):extended;
    begin
      dist:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    end;
  procedure cut(flag:boolean);
    var
      i:longint;
      a2,b2,c2,xx,yy:extended;
    begin
      x[kh+1]:=x[1];
      y[kh+1]:=y[1];
      kh2:=0;
      kh3:=0;
      for i:=1 to kh do begin 
        if (sq(x[i],y[i],a,b,c)<eps)then begin
          inc(kh2);x2[kh2]:=x[i];y2[kh2]:=y[i];
        end;
        if (sq(x[i],y[i],a,b,c)>-eps)then begin
          inc(kh3);x3[kh3]:=x[i];y3[kh3]:=y[i];
        end;
        if (sq(x[i],y[i],a,b,c)*sq(x[i+1],y[i+1],a,b,c)<0)then begin
          line(x[i],y[i],x[i+1],y[i+1],a2,b2,c2);
          cross(a2,b2,c2,a,b,c,xx,yy);
          if (abs(dist(x[i],y[i],xx,yy)+dist(xx,yy,x[i+1],y[i+1])-dist(x[i],y[i],x[i+1],y[i+1]))<eps)then begin
            inc(kh2);x2[kh2]:=xx;y2[kh2]:=yy;
            inc(kh3);x3[kh3]:=xx;y3[kh3]:=yy;
          end;
        end;
      end;
      if (flag)then begin
        kh2:=kh3;
        x2:=x3;
        y2:=y3;
      end;
    end;
begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,h,f);
  res:=0;
  for i:=1 to n do begin
    read(l[i],r[i]);
    line(0,f,l[i],h,a,b,c);
    lx[i]:=(b*h-c)/a;
    line(0,f,r[i],h,a,b,c);
    rx[i]:=(b*h-c)/a;
    res:=res+h*(r[i]-l[i]+rx[i]-lx[i]);
  end;
  res:=res+res;
  for i:=1 to n do 
    for j:=1 to n do begin
      y[1]:=h;x[1]:=lx[j];
      y[2]:=h;x[2]:=rx[j];
      y[3]:=-h;x[3]:=r[j];
      y[4]:=-h;x[4]:=l[j];
      kh:=4;
      line(0,f,r[i],h,a,b,c);
      cut(true);
      if (kh2<3)then continue;
      kh:=kh2;
      x:=x2;
      y:=y2;
      line(0,f,l[i],h,a,b,c);
      cut(false);
      kh:=kh2;
      x:=x2;
      y:=y2;
      if (kh<3)then continue;
      x[kh+1]:=x[1];
      y[kh+1]:=y[1];
      ss:=0;
      for t:=1 to kh do 
        ss:=ss+(x[t+1]-x[t])*(y[t]+y[t+1])/2;
      ss:=abs(ss);
      res:=res-ss;
    end;
  writeln(res:0:10);
  close(output);close(input);
end.
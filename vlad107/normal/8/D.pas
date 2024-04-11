{$r-,q-,s-,i-,o+}
const
  eps=1e-10;
  eps2=1e-10;

var
  cr,r1,r2,sr,ll,rr,sx,sy,xa,ya,xb,yb,t1,t2:extended;
  it:longint;
  found:boolean;
  
  function dist(x1,y1,x2,y2:extended):extended;
    begin
      dist:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    end;

  procedure check(x,y:extended);
    begin
      if (dist(x,y,sx,sy)<=sr+eps2)and
         (dist(x,y,xa,ya)<=r1+eps2)and
         (dist(x,y,xb,yb)<=r2+eps2)
           then found:=true;
    end;
    
  procedure cross(x1,y1,r1,x2,y2,r2:extended);
    var
      a,b,c,d,x0,y0,l:extended;
      
    begin
      x2:=x2-x1;y2:=y2-y1;
      a:=2*x2;
      b:=2*y2;
      c:=-x2*x2-y2*y2+r2*r2-r1*r1;
      d:=sqrt(a*a+b*b);
      a:=a/d;b:=b/d;c:=c/d;
      d:=abs(c);
      if (d>r1+eps)then exit;
      x0:=-a*c;
      y0:=-b*c;
      if (abs(d-r1)<eps)then begin
        check(x0+x1,y0+y1);
        exit;
      end;
      l:=r1*r1-d*d;
      if (l<0)then l:=0;
      l:=sqrt(l);
      check(x0-b*l+x1,y0+a*l+y1);
      check(x0+b*l+x1,y0-a*l+y1);
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(t2,t1,sx,sy,xa,ya,xb,yb);
  t1:=t1+dist(sx,sy,xa,ya);
  t2:=t2+dist(sx,sy,xb,yb)+dist(xa,ya,xb,yb);
  ll:=0;rr:=1e9;
  for it:=1 to 1000 do begin
    sr:=(ll+rr)/2;
    r1:=t1-sr;
    r2:=t2-dist(xa,ya,xb,yb)-sr;
    if (abs(r1)<eps)then r1:=0;
    if (abs(r2)<eps)then r2:=0;
    if (r1<-eps)or(r2<-eps)then begin
      rr:=sr;
      continue;
    end;
    found:=false;
    check(xa,ya);
    check(xb,yb);
    check(sx,sy);
    cross(xa,ya,r1,xb,yb,r2);
    cross(sx,sy,sr,xa,ya,r1);
    cross(sx,sy,sr,xb,yb,r2);
    if (not found)then rr:=sr else ll:=sr;
  end;
  cr:=dist(sx,sy,xb,yb)+dist(xb,yb,xa,ya);
  if (cr<=t1+eps)then begin
    if (t1<t2)then cr:=t1 else cr:=t2;
    if (cr>sr)then sr:=cr;
  end;
  writeln(sr:0:10);
  close(output);close(input);
end.
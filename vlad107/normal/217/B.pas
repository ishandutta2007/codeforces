
const
  inf=1000000000;

var
  kx,xx,yy,kt,min,x,y,i,n,r:longint;
  ans:array[0..2000500]of char;

  procedure check(x,y:longint);
    var
      qx,qy,kx,tr,cr:longint;
      
    begin
      qx:=x;qy:=y;
      tr:=0;
      cr:=0;
      while (x<>1)or(y<>1)do begin
        if (x=1)or(y=1)then begin
          if (x<>1)then inc(cr);
          inc(tr,x+y-2);
          if (tr>n)then exit;
          inc(cr,x+y-3);
          x:=1;
          y:=1;
          continue;
        end;
        if (x=0)or(y=0)then exit;
        if (x=y)then exit;
        if (x>y)then begin
          kx:=x div y;
          inc(tr,kx);
          if (tr>n)then exit;
          dec(x,kx*y);
          inc(cr,kx-1);
        end else begin
          kx:=y div x;
          inc(tr,kx);
          if (tr>n)then exit;
          dec(y,kx*x);
          inc(cr,kx-1);
        end;
      end;
      if (tr<>n)then exit;
      if (cr<min)then begin
        min:=cr;
        xx:=qx;yy:=qy;
      end;
    end;

begin
  read(n,r);
  if (n=1)and(r=1)then begin
    writeln(0);
    writeln('T');
    exit;
  end;  
  dec(n);
  min:=inf;
  for i:=1 to r-1 do begin
    check(r,i);
    check(i,r);
  end;
  if (min=inf)then begin
    writeln('IMPOSSIBLE');
    exit;
  end;
  writeln(min);
  x:=xx;y:=yy;
  kt:=n+1;
  ans[1]:='T';
  for i:=kt downto 2 do 
    if (x>y)then begin
      dec(x,y);
      ans[i]:='T'
    end else begin
      dec(y,x);
      ans[i]:='B';
    end;
  for i:=1 to kt do write(ans[i]);
  writeln;
end.
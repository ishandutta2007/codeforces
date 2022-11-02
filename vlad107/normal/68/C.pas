{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  x,y,i,r1,r2,n:longint;
  t:array[0..10]of longint;
  sl,fl,al:array[0..10,0..10]of longint;
  procedure rec(x,y,k:longint); 
    var
      nx,ny,i:longint;
    begin
      if (t[1]>r1)then exit;
      if (x=n-1)then begin
        if (x=1)then begin
          r1:=sl[1][2];
          r2:=sl[1][2]*sl[1][2];
          if (r2<>0)then inc(r2,al[1][2]);
          exit;
        end;
        if (t[x]<sl[x][y])or(t[x]>fl[x][y])then exit;
        k:=k+t[x]*t[x];
        if (t[x]<>0)then k:=k+al[x][y];
        if (r1=t[1])and(k<r2)then exit;
        r1:=t[1];
        r2:=k;
        exit;
      end;
      if (x=1)then begin
        for i:=sl[x][y]to fl[x][y]do begin 
          inc(t[y],i);
          inc(t[1],i);
          if (y=n)then begin
            nx:=x+1;
            ny:=x+2;
          end else begin
            nx:=x;
            ny:=y+1;
          end;
          if (t[1]<=r1)then rec(nx,ny,k+i*i+ord(i<>0)*al[x][y]);
          dec(t[1],i);
          dec(t[y],i);
        end;
        exit;
      end;
      if (y<>n)then begin
        for i:=sl[x][y]to fl[x][y]do begin 
          if (i>t[x])then break;
          inc(t[y],i);
          dec(t[x],i);
          if (y=n)then begin
            nx:=x+1;
            ny:=x+2;
          end else begin
            nx:=x;
            ny:=y+1;
          end;
          rec(nx,ny,k+i*i+ord(i<>0)*al[x][y]);
          inc(t[x],i);
          dec(t[y],i);
        end;        
      end else begin
        if (t[x]<sl[x][y])or(t[x]>fl[x][y])then exit;
        if (y=n)then begin
          nx:=x+1;
          ny:=x+2;
        end else begin
          nx:=x;
          ny:=y+1;
        end;
        rec(nx,ny,k+t[x]*t[x]+ord(t[x]<>0)*al[x][y]);
      end;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n*(n-1)shr 1 do begin
    read(x,y);
    read(sl[x][y],fl[x][y],al[x][y]);
  end;
  r1:=26;r2:=-1;
  fillchar(t,sizeof(t),$0);
  rec(1,2,0);
  if (r1=26)then r1:=-1;
  writeln(r1,' ',r2);
end.
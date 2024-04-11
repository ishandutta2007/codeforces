{$r-,q-,s-,i-,o+}
var
  n,sx,sy,ex,ey:longint;
  d:array[0..1111,0..1111]of longint;
  procedure rec(x,y,k:longint);
    begin
      if (x>n)or(y>n)or(x<0)or(y<0)then exit;
      if (k>=d[x][y])and(d[x][y]>-1)then exit;
      d[x][y]:=k;
      if (x=0)or(x=n)then begin
        rec(x,y+1,k+1);
        rec(x,y-1,k+1);
      end;
      if (y=0)or(y=n)then begin
        rec(x+1,y,k+1);
        rec(x-1,y,k+1);
      end;
    end;
begin
  read(n,sx,sy,ex,ey);
  fillchar(d,sizeof(d),$FF);
  rec(sx,sy,0);
  writeln(d[ex][ey]);
end.
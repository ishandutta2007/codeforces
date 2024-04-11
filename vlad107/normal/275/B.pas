{$r-,q-,s-,i-,o+}
var
  a:array[0..555,0..555]of char;
  d:array[0..555,0..555]of longint;
  was:array[0..555,0..555,0..5]of longint;
  qz,qx,qy:array[0..500500]of longint;
  qqq,z,h,qb,qe,x,y,cx,cy,i,j,n,m:longint;
  
  procedure add(x,y,z:longint);
    begin
      if (x<1)or(y<1)or(x>n)or(y>m)or(a[x][y]='W')then exit;
      if (was[x][y][z]=qqq)then exit;
      inc(qe);qx[qe]:=x;qy[qe]:=y;qz[qe]:=z;
      was[x][y][z]:=qqq;
    end;

  procedure calc(sx,sy:longint);
    var
      i,j:longint;
      
    begin
      qb:=0;qe:=0;
      inc(qqq);
      for i:=sy to m do if (a[sx][i]='B')then add(sx,i,1) else break;
      for i:=sy-1 downto 1 do if (a[sx][i]='B')then add(sx,i,1) else break;
      for i:=sx to n do if (a[i][sy]='B')then add(i,sy,2)else break;
      for i:=sx-1 downto 1 do if (a[i][sy]='B')then add(i,sy,2)else break;
      while (qb<qe)do begin
        inc(qb);
        x:=qx[qb];y:=qy[qb];z:=qz[qb];
        if (z=1)then begin add(x+1,y,z);add(x-1,y,z); end else
        begin add(x,y+1,z);add(x,y-1,z); end;
      end;
      for i:=1 to n do 
        for j:=1 to m do 
          if (a[i][j]='B')and(was[i][j][1]<>qqq)and(was[i][j][2]<>qqq)then begin
            writeln('NO');halt(0);
          end;
    end;

begin
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  for i:=1 to n do for j:=1 to m do if (a[i][j]='B')then calc(i,j);
  writeln('YES');
end.
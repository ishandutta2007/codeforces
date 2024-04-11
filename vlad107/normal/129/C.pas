const
  hx:array[1..9]of longint=(0,-1,-1,0,1,-1, 0,1, 1);
  hy:array[1..9]of longint=(1, 0, 1,0,1,-1,-1,0,-1);
var
  a:array[0..10,0..10]of char;
  it,i,j:longint;
  procedure rec(x,y,k:longint);
    var
      q,cx,cy:longint;
    begin
      inc(it);
      if (it>10000000)then begin
        writeln('LOSE');
        halt(0);
      end;
      if (x=1)then begin
        writeln('WIN');
        halt(0);
      end;
      for q:=1 to 9 do begin
        cx:=x+hx[q];
        cy:=y+hy[q];
        if (cx>8)or(cy<1)or(cx<1)or(cy>8)then continue;
        if (cx>=k)and(a[cx-k+1][cy]='S')then continue;
        if (cx>k)and(a[cx-k][cy]='S')then continue;
        rec(cx,cy,k+1);
      end;
    end;

begin
  for i:=1 to 8 do begin
    for j:=1 to 8 do read(a[i][j]);
    readln;
  end;
  rec(8,1,1);
  writeln('LOSE');
end.
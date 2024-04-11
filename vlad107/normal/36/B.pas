var
  nm,n,m,i,j:longint;
  a,b:array[1..500,1..500]of char;
  procedure rec(lx,ly,rx,ry:longint);
    var
      i,j,k,x,y,i2,j2:longint;
    begin
      if (rx-lx+1=n)then begin
        for i:=lx to rx do
          for j:=ly to ry do
            a[i][j]:=b[i-lx+1][j-ly+1];
        exit;
      end;
      k:=(rx-lx+1)div n;
      i:=lx;j:=ly;
      for x:=1 to n do for y:=1 to n do begin
        if (b[x][y]='*')then begin
          for i2:=i to i+k-1 do for j2:=j to j+k-1 do a[i2][j2]:='*';
        end else rec(i,j,i+k-1,j+k-1);
        inc(j,k);
        if (j>ry)then begin
          j:=ly;
          inc(i,k);
        end;
      end;
    end;
begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to n do read(b[i][j]);
    readln;
  end;
  j:=1;
  for i:=1 to m do j:=j*n;
  nm:=j;
  rec(1,1,j,j);
  for i:=1 to nm do begin
    for j:=1 to nm do write(a[i][j]);
    writeln;
  end;
  close(output);
  close(input);
end.
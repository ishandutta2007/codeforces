{$r-,q-,s-,i-,o+}
const
  ang:array[1..5]of extended=(0,216,72,288,144);
  LEN:extended=16.18033988749895;
  startX:extended=0;
  startY:extended=0;

var
  tx,ty:array[0..500500]of extended;
  q:array[0..500500]of longint;
  j,i,n,m,kq:longint;
  g:array[0..555,0..555]of longint;
  kg:array[0..555]of longint;
  
  procedure add(x,y:longint);
    begin
      inc(kg[x]);
      g[x][kg[x]]:=y;
    end;

  procedure next(x,y:extended;t:longint;var nx,ny:extended);
    var
      aa:extended;
      
    begin
      aa:=ang[t]*pi/180;
      nx:=cos(aa)*len;
      ny:=sin(aa)*len;
      nx:=nx+x;
      ny:=ny+y;
    end;

  procedure dfs(x,y:extended;k:longint);
    var
      nx,ny:extended;
      i,sm:longint;
       
    begin
      next(x,y,1,nx,ny);
      sm:=m;
      add(n-k+1,m);
      inc(m);
      tx[m]:=nx;ty[m]:=ny;
      inc(kq);
      q[kq]:=m;
      add(n-k+1,m);
      if (k>1)then dfs(nx,ny,k-1);
      for i:=2 to 5 do begin
        next(nx,ny,i,nx,ny);
        if (i=5)then begin
          inc(kq);
          q[kq]:=sm;
        end else begin
          inc(m);
          tx[m]:=nx;ty[m]:=ny;
          inc(kq);
          q[kq]:=m;
          add(n-k+1,m);
        end;
      end;
    end;

begin
  read(n);
  m:=1;
  tx[1]:=startX;ty[1]:=startY;
  kq:=1;
  q[1]:=1;
  dfs(startX,startY,n);
  writeln(m);
  for i:=1 to m do writeln(tx[i]:0:10,' ',ty[i]:0:10);
  for i:=1 to n do writeln(g[i][4],' ',g[i][2],' ',g[i][5],' ',g[i][3],' ',g[i][1]);
  for i:=1 to kq do write(q[i],' ');
  writeln;
end.
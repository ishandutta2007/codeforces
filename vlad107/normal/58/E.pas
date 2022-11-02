{$r-,q-,s-,i-,o+}
type
  TPred=record
    px,py,pz,pi,pj,pk,post,x,y,z:longint;
  end;

var
  a,b,c,s:ansistring;
  min,tx,ty,tz,nx,ny,nz,px,py,pz,cr,i,j,k,ost,nost,x,y,z,ni,nj,nk,la,lb,lc:longint;
  f:array[0..11,0..11,0..11,0..1,0..11,0..11,0..11]of longint;
  pred:array[0..11,0..11,0..11,0..1,0..11,0..11,0..11]of TPred;

begin
  readln(s);
  a:=copy(s,1,pos('+',s)-1);
  delete(s,1,pos('+',s));
  b:=copy(s,1,pos('=',s)-1);
  delete(s,1,pos('=',s));
  c:=s;
  la:=length(a);
  lb:=length(b);
  lc:=length(c);
  fillchar(f,sizeof(f),$ff);
  f[0][0][0][0][0][0][0]:=0;
  for i:=0 to la do 
    for j:=0 to lb do 
      for k:=0 to lc do 
        for ost:=1 downto 0 do 
          for tx:=0 to 10 do 
            for ty:=0 to 10 do 
              for tz:=0 to 10 do 
                if (f[i][j][k][ost][tx][ty][tz]<>-1)then begin
                  for x:=0 to 9 do 
                    for y:=0 to 9 do begin
                      z:=x+y+ost;
                      nost:=z div 10;
                      z:=z mod 10;
                      if (i<la)
                        then ni:=i+ord(ord(a[la-i])-48=x)
                        else ni:=i;
                      if (j<lb)
                        then nj:=j+ord(ord(b[lb-j])-48=y)
                        else nj:=j;
                      if (k<lc)
                        then nk:=k+ord(ord(c[lc-k])-48=z)
                        else nk:=k;
                      if (ni=i)and(nj=j)and(nk=k)and(nost>=ost)then continue;
                      nx:=tx;ny:=ty;nz:=tz;
                      if (x=0)then inc(nx)else nx:=0;
                      if (y=0)then inc(ny)else ny:=0;
                      if (z=0)then inc(nz)else nz:=0;
                      cr:=f[i][j][k][ost][tx][ty][tz]+ord(i=ni)+ord(j=nj)+ord(k=nk);
                      if (f[ni][nj][nk][nost][nx][ny][nz]=-1)or(cr<f[ni][nj][nk][nost][nx][ny][nz])then begin
                        f[ni][nj][nk][nost][nx][ny][nz]:=cr;
                        pred[ni][nj][nk][nost][nx][ny][nz].pi:=i;
                        pred[ni][nj][nk][nost][nx][ny][nz].pj:=j;
                        pred[ni][nj][nk][nost][nx][ny][nz].pk:=k;
                        pred[ni][nj][nk][nost][nx][ny][nz].post:=ost;
                        pred[ni][nj][nk][nost][nx][ny][nz].px:=tx;
                        pred[ni][nj][nk][nost][nx][ny][nz].py:=ty;
                        pred[ni][nj][nk][nost][nx][ny][nz].pz:=tz;
                        pred[ni][nj][nk][nost][nx][ny][nz].x:=x;
                        pred[ni][nj][nk][nost][nx][ny][nz].y:=y;
                        pred[ni][nj][nk][nost][nx][ny][nz].z:=z;
                      end;
                    end;
                end;
  min:=100500;
  for i:=0 to 10 do 
    for j:=0 to 10 do 
      for k:=0 to 10 do 
        if (f[la][lb][lc][0][i][j][k]<>-1)and(f[la][lb][lc][0][i][j][k]-i-j-k<min)then begin
          min:=f[la][lb][lc][0][i][j][k]-i-j-k;
          x:=i;y:=j;z:=k;
        end;
  a:='';b:='';c:='';
  i:=la;j:=lb;k:=lc;ost:=0;
  while (i>0)or(j>0)or(k>0)do begin
    ni:=pred[i][j][k][ost][x][y][z].pi;
    nj:=pred[i][j][k][ost][x][y][z].pj;
    nk:=pred[i][j][k][ost][x][y][z].pk;
    nost:=pred[i][j][k][ost][x][y][z].post;
    px:=pred[i][j][k][ost][x][y][z].px;
    py:=pred[i][j][k][ost][x][y][z].py;
    pz:=pred[i][j][k][ost][x][y][z].pz;
    a:=a+chr(pred[i][j][k][ost][x][y][z].x+48);
    b:=b+chr(pred[i][j][k][ost][x][y][z].y+48);
    c:=c+chr(pred[i][j][k][ost][x][y][z].z+48);
    i:=ni;j:=nj;k:=nk;ost:=nost;x:=px;y:=py;z:=pz;
  end;
  while (a[1]='0')do delete(a,1,1);
  while (b[1]='0')do delete(b,1,1);
  while (c[1]='0')do delete(c,1,1);
  writeln(a,'+',b,'=',c);
end.
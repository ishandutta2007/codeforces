{$r-,q-,s-,i-,o+}
const
  hx:array[1..4]of longint=(0,0,-1,1);
  hy:array[1..4]of longint=(-1,1,0,0);

var
  a:array[0..1111,0..1111]of char;
  was,used:array[0..1111,0..1111]of longint;
  ii,tx,ct,jj,x,y,cu,n,m,kg,qb,qe,qqq,i,j,cr,d:longint;
  ux,uy,xr,yr,gx,gy,pred,last,qx,qy,qz:array[0..500500]of longint;
  ff:boolean;

  procedure add(sx,sy,cr:longint);
    var
      x,y,z,cx,cy,i:longint;
      
    begin
      qb:=0;qe:=1;
      qx[1]:=sx;
      qy[1]:=sy;
      qz[1]:=d;
      inc(qqq);
      used[sx][sy]:=qqq;
      while (qb<qe)do begin
        inc(qb);
        x:=qx[qb];
        y:=qy[qb];
        z:=qz[qb];
        inc(kg);
        gx[kg]:=x;
        gy[kg]:=y;
        pred[kg]:=last[cr];
        last[cr]:=kg;
        if (z=0)then continue;
        for i:=1 to 4 do begin
          cx:=x+hx[i];
          cy:=y+hy[i];
          if (cx<1)or(cy<1)or(cx>n)or(cy>m)or(a[cx][cy]='X')then continue;
          if (used[cx][cy]=qqq)then continue;
          used[cx][cy]:=qqq;
          inc(qe);
          qx[qe]:=cx;
          qy[qe]:=cy;
          qz[qe]:=z-1;
        end;
      end;
    end;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(n,m,d);
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(a[i][j]);
      if (a[i][j]='R')then begin
        inc(cr);
        xr[cr]:=i;
        yr[cr]:=j;
      end;
    end;
    readln;
  end;
  if (cr>2*(d*d+(d+1)*(d+1)))then begin
    writeln(-1);
    exit;
  end;
  qqq:=0;
  for i:=1 to cr do add(xr[i],yr[i],i);
  fillchar(was,sizeof(was),$0);
  for tx:=1 to cr do begin
    ii:=last[tx];
    while (ii>0)do begin
      x:=gx[ii];
      y:=gy[ii];
      ct:=0;
      cu:=0;
      for i:=1 to cr do begin
        ff:=false;
        jj:=last[i];
        while (jj>0)do begin
          if (gx[jj]=x)and(gy[jj]=y)then begin
            ff:=true;
            break;
          end;
          jj:=pred[jj];
        end;
        if (ff)then continue;
        inc(ct);
        jj:=last[i];
        while (jj>0)do begin
          inc(was[gx[jj]][gy[jj]]);
          inc(cu);
          ux[cu]:=gx[jj];
          uy[cu]:=gy[jj];
          jj:=pred[jj];
        end;
      end;
      if (ct=0)then begin
        write(x,' ',y);
        for i:=1 to n do 
          for j:=1 to m do 
            if ((i<>x)or(j<>y))and(a[i][j]<>'X')then begin
              writeln(' ',i,' ',j);
              exit;
            end;
      end;
      for i:=1 to cu do 
        if (was[ux[i]][uy[i]]=ct)then begin
          writeln(x,' ',y,' ',ux[i],' ',uy[i]);
          exit;
        end else was[ux[i]][uy[i]]:=0;
      ii:=pred[ii];
    end;
  end;
  writeln(-1);
end.
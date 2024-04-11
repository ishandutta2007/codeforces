{$r-,q-,s-,i-,o+}
{$M 10000000}
const
  inf:int64=9000000000000000000;
var
  k,j,ttt,finish,kn,ks,n,m,i:longint;
  res,gg,ss:int64;
  nom,p,g:array[0..1111,0..1111]of longint;
  kg:array[0..1111]of longint;
  a,b,x,y:array[0..50500]of longint;
  procedure qs(l,r:longint);
    var
      xx,i,j,nn,tmp:longint;
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=a[nn];
      while (i<=j)do begin
        while (xx>a[i])do inc(i);
        while (xx<a[j])do dec(j);
        if (i>j)then break;
        tmp:=x[i];x[i]:=x[j];x[j]:=tmp;
        tmp:=y[i];y[i]:=y[j];y[j]:=tmp;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  procedure dfs(x,px,mx,nx,ny:longint);
    var
      y,nx2,ny2,pnx,pny,pmx,i:longint;
    begin
      if (finish<0)then exit;
      if (x=finish)then begin
        finish:=-1;
        if (mx<=ttt)then begin
          ttt:=0;
          exit;
        end;
        y:=g[nx][ny];
        nx2:=y;ny2:=nom[y][nx];
        g[nx,ny]:=g[nx,kg[nx]];
        p[nx,ny]:=p[nx,kg[nx]];
        dec(kg[nx]);
        nom[nx][g[nx,ny]]:=ny;
        nx:=nx2;ny:=ny2;
        g[nx][ny]:=g[nx,kg[nx]];
        p[nx][ny]:=p[nx,kg[nx]];
        dec(kg[nx]);
        nom[nx][g[nx,ny]]:=ny;
        exit;
      end;
      for i:=1 to kg[x] do begin
        y:=g[x][i];
        if (y=px)then continue;
        pmx:=mx;pnx:=nx;pny:=ny;
        if (p[x][i]>mx)then begin
          mx:=p[x][i];nx:=x;ny:=i;
        end;
        dfs(y,x,mx,nx,ny);
        mx:=pmx;nx:=pnx;ny:=pny;
      end;
    end;
begin
  randomize;
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m,gg,ss);
  for i:=1 to m do read(x[i],y[i],a[i],b[i]);
  qs(1,m);
  ks:=0;
  res:=-1;
  kn:=n;
  for i:=1 to m do begin
    finish:=y[i];
    ttt:=b[i];
    dfs(x[i],0,0,0,0);
    if (finish<>-1)then begin
      dec(kn);
      inc(kg[x[i]]);g[x[i],kg[x[i]]]:=y[i];p[x[i],kg[x[i]]]:=b[i];
      inc(kg[y[i]]);g[y[i],kg[y[i]]]:=x[i];p[y[i],kg[y[i]]]:=b[i];
      nom[x[i],y[i]]:=kg[x[i]];
      nom[y[i],x[i]]:=kg[y[i]];
    end else 
      if (ttt<>0)then begin
        inc(kg[x[i]]);g[x[i],kg[x[i]]]:=y[i];p[x[i],kg[x[i]]]:=b[i];
        inc(kg[y[i]]);g[y[i],kg[y[i]]]:=x[i];p[y[i],kg[y[i]]]:=b[i];
        nom[x[i],y[i]]:=kg[x[i]];
        nom[y[i],x[i]]:=kg[y[i]];
      end;   
    ks:=0;
    for j:=1 to n do 
      for k:=1 to kg[j]do 
        if (p[j][k]>ks)then ks:=p[j][k];
    if (kn=1)and((res=-1)or(gg*a[i]+ss*ks<res))then res:=gg*a[i]+ss*ks;
  end;
  writeln(res);
  close(output);
  close(input);
end.
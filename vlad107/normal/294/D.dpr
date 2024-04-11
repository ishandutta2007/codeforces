{$r-,q-,s-,i-,o+}
const
  way:array[1..4]of string=('UL','UR','DL','DR');
  hx:array[1..4]of longint=(-1,-1,1,1);
  hy:array[1..4]of longint=(-1,1,-1,1);

var
  j,x,y,kol,nx,ny,nt,t,n,m,xs,ys,i:longint;
  ans:int64;
  ts:ansistring;
  u1,u2,u3,u4:array[0..500500]of boolean;//x=1,x=n,y=1,y=m
  w1,w2,w3,w4:array[0..5,0..500500]of boolean;
  
  function was1(x,y:longint):boolean;
    begin
      if (x=1)then was1:=u1[y] else
      if (x=n)then was1:=u2[y] else
      if (y=1)then was1:=u3[x] else
      was1:=u4[x];
    end;
    
  function was2(x,y,t:longint):boolean;
    begin
      if (x=1)then was2:=w1[t][y] else
      if (x=n)then was2:=w2[t][y] else
      if (y=1)then was2:=w3[t][x] else
      was2:=w4[t][x];    
    end;
    
  procedure next(x,y,t:longint;var nx,ny,nt:longint);
    var
      time,tx,ty,ux,uy:longint;
    begin
      if (hx[t]=1)then tx:=(n-x) else tx:=x-1;
      if (hy[t]=1)then ty:=(m-y) else ty:=y-1;
      if (tx<ty)then time:=tx else time:=ty;
      nx:=x+hx[t]*time;
      ny:=y+hy[t]*time;
      if (nx=1)or((hx[t]=1)and(nx<>n))then ux:=1 else ux:=-1;
      if (ny=1)or((hy[t]=1)and(ny<>m))then uy:=1 else uy:=-1;
      nt:=1;
      while (hx[nt]<>ux)or(hy[nt]<>uy)do inc(nt);
    end;
    
  procedure block(x,y,t:longint);
    begin
      if (x=1)then begin
        u1[y]:=true;
        w1[t][y]:=true;
      end;
      if (x=n)then begin
        u2[y]:=true;
        w2[t][y]:=true;
      end;
      if (y=1)then begin
        u3[x]:=true;
        w3[t][x]:=true;
      end;
      if (y=m)then begin
        u4[x]:=true;
        w4[t][x]:=true;
      end;
    end;

begin
//  assign(input,'input.txt');reset(input);
  readln(n,m);
  readln(xs,ys,ts);
  delete(ts,1,1);
  i:=1;
  while (ts<>way[i])do inc(i);
  t:=i;
  kol:=0;
  for i:=1 to n do begin
    if ((i+1)mod 2=(xs+ys)mod 2)then inc(kol);
    if ((i+m)mod 2=(xs+ys)mod 2)then inc(kol);
  end;
  for j:=2 to m-1 do begin
    if ((j+1)mod 2=(xs+ys)mod 2)then inc(kol);
    if ((j+n)mod 2=(xs+ys)mod 2)then inc(kol);
  end;
  ans:=1;
  dec(kol);
  x:=xs;y:=ys;
  block(x,y,t);
  while (true)do begin
    next(x,y,t,nx,ny,nt);
    if (was2(nx,ny,nt))then begin
      writeln(-1);
      exit;
    end;
    ans:=ans+abs(nx-x);
    x:=nx;y:=ny;t:=nt;
    if (not was1(x,y))then dec(kol);
    if (kol=0)then break;
    block(x,y,t);
  end;
  writeln(ans);
end.
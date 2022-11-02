{$r-,q-,s-,i-,o+}
const
  MAXN=2020;
var
  was,deg,rg,gg:array[0..MAXN]of longint;
  g:array[0..MAXN,0..MAXN]of boolean;
  oo,ty,n,m,i,j,x,y:longint;
  procedure delG(x,y:longint);
    begin
      dec(deg[x]);
      dec(deg[y]);
      g[x][y]:=false;
      g[y][x]:=false;
    end;
  procedure addG(x,y:longint);
    begin
      inc(deg[x]);
      inc(deg[y]);
      g[x][y]:=true;
      g[y][x]:=true;
    end;
  procedure init;
    begin
      fillchar(g,sizeof(g),false);
      fillchar(deg,sizeof(deg),$0);
    end;
  procedure dfs(x:longint);
    var
      i:longint;
    begin
      if (was[x]=oo)then exit;
      was[x]:=oo;
      for i:=1 to n do
        if (g[x][i])then dfs(i);
    end;
  function ok(xx,yy:longint):boolean;
    var
      i:longint;
    begin
      ok:=true;
      inc(oo);
      dfs(xx);
      for i:=1 to n do
        if (deg[i]<>0)and(was[i]<>oo)then begin
          ok:=false;exit;
        end;
      if (xx=yy)then begin
        for i:=1 to n do
          if (deg[i] mod 2<>0)then begin
            ok:=false;exit;
          end;
      end else begin
        if (deg[xx]mod 2<>1)or(deg[yy]mod 2<>1)then begin
           ok:=false;exit;
        end;
        for i:=1 to n do
          if (i<>xx)and(i<>yy)and(deg[i]mod 2<>0)then begin
            ok:=false;exit;
          end;
      end;
    end;
begin
  init;
  read(n,m);
  oo:=0;
  for i:=1 to m+1 do read(gg[i]);
  for i:=1 to m do addG(gg[i],gg[i+1]);
  x:=-1;
  for i:=1 to m do begin
    y:=gg[i+1]+1;
    while (y<=n)do begin
      if (g[gg[i]][y]=false)then begin
        inc(y);
        continue;
      end;
      delG(gg[i],y);
      if (ok(y,gg[1]))then begin
        addG(gg[i],y);
        break;
      end;
      addG(gg[i],y);
      inc(y);
    end;
    if (y<=n)then x:=i;
    delG(gg[i],gg[i+1]);
  end;
  if (x<0)then begin
    writeln('No solution');
    halt(0);
  end;
  init;
  for i:=1 to m do addG(gg[i],gg[i+1]);
  for i:=1 to x-1 do delG(gg[i],gg[i+1]);
  for i:=1 to m+1 do rg[i]:=gg[i];
  y:=gg[x+1]+1;
  while (true)do begin
    if (g[gg[x]][y]=false)then begin
      inc(y);
      continue;
    end;
    delG(gg[x],y);
    if (ok(y,gg[1]))then break;
    addG(gg[x],y);
    inc(y);
  end;
  rg[x+1]:=y;
  ty:=y;
  for i:=x+1 to m do begin
    y:=1;
    while (true) do begin
      if (g[ty][y]=false)then begin
        inc(y);
        continue;
      end;
      delG(ty,y);
      if (ok(y,gg[1]))then break;
      addG(ty,y);
      inc(y);
    end;
    rg[i+1]:=y;
    ty:=y;
  end;
  for i:=1 to m+1 do write(rg[i],' ');
end.
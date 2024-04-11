{$r-,q-,s-,i-,o+}
var
  ok:boolean;
  x,y,i,j,n,m:longint;
  g,a:array[1..1000,1..1000]of boolean;
  was,deg:array[1..1000]of longint;
  procedure out(s:string);
    begin
      writeln(s);
      halt(0);
    end;
  procedure dfs(x:longint);
    var
      i:longint;
    begin
      was[x]:=1;
      for i:=1 to n do 
        if (was[i]=0)and(g[x][i])then dfs(i);
    end;
  procedure dfs2(x,px:longint;flag:boolean);
    var
      i:longint;
    begin
      was[x]:=1;
      for i:=1 to n do if (i<>px)then begin
        if (g[x][i])and(was[i]=1)then begin
          if (flag)then ok:=false else out('NO');
        end else
        if (g[x][i])and(was[i]=0)then dfs2(i,x,flag);
      end;
      was[x]:=2;
    end;
  function good():boolean;
    var
      i:longint;
    begin
      good:=false;
      if (m>n)then exit;
      ok:=true;
      for i:=1 to n do 
        if (deg[i]>2)then exit;
      for i:=1 to n do 
        if (deg[i]<2)then begin
          ok:=false;
          break;
        end;                                                         
      fillchar(was,sizeof(was),$0);
      dfs(1);
      for i:=1 to n do 
        if (was[i]=0)then begin
          ok:=false;
          break;
        end;
      if (ok)then begin
        good:=true;
        exit;
      end;
      fillchar(was,sizeof(was),$0);
      ok:=true;
      for i:=1 to n do dfs2(i,0,true);
      good:=ok;
    end;
begin
  read(n,m);
  if (m>n)then out('NO');
  fillchar(g,sizeof(g),false);
  fillchar(a,sizeof(a),false);
  fillchar(deg,sizeof(deg),$0);
  for i:=1 to m do begin
    read(x,y);
    if (g[x][y] or g[y][x])and(n<>m)then out('NO');
    g[x][y]:=true;
    g[y][x]:=true;
    a[x][y]:=true;
    a[y][x]:=true;
    inc(deg[x]);
    inc(deg[y]);
  end;
  ok:=true;
  for i:=1 to n do 
    if (deg[i]>2)then out('NO');
  for i:=1 to n do 
    if (deg[i]<2)then begin
      ok:=false;
      break;
    end;                                                         
  fillchar(was,sizeof(was),$0);
  dfs(1);
  for i:=1 to n do 
    if (was[i]=0)then begin
      ok:=false;
      break;
    end;
  if (ok)then begin
    writeln('YES');
    writeln(0);
    exit;
  end;
  fillchar(was,sizeof(was),$0);
  for i:=1 to n do dfs2(i,0,false);
  writeln('YES');
  if (n=1)then begin
    writeln(1);
    writeln('1 1');
    exit;
  end;
  if (n=2)then begin
    writeln(n-m);
    writeln('1 2');
    if (m=0)then writeln('1 2');
    exit;
  end;
  writeln(n-m);
  i:=1;
  for i:=1 to n do 
    for j:=i+1 to n do begin
      if (g[i][j])then continue;
      g[i][j]:=true;
      g[j][i]:=true;
      inc(deg[i]);
      inc(deg[j]);
      inc(m);
      if (good())then continue;
      dec(m);
      dec(deg[i]);
      dec(deg[j]);
      g[i][j]:=false;
      g[j][i]:=false;
    end;
  for i:=1 to n do
    for j:=i to n do 
      if (g[i][j]<>a[i][j])
        then writeln(i,' ',j);
end.
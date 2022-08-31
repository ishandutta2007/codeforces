{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const dx: array [1..4] of longint = (0,1,0,-1);
      dy: array [1..4] of longint = (1,0,-1,0);
var
  best,cur: array [0..5555] of char;
  x,y,nx,ny: array [0..5555] of longint;
  d: array [0..55,0..55] of longint;
  was,b: array [0..55,0..55] of boolean;
  a: array [0..55,0..55] of char;
  k,xk,yk,xs,ys,xt,yt,ans,len,e,ne,i,j,n,m: longint;
  min: char;
  ok: boolean;

procedure rec(v,w:longint);
var
  q,i,j: longint;
begin
  if v = 27 then
  begin
    for i:=1 to n do
      for j:=1 to m do
        if b[i,j] then d[i,j]:=-1
        else d[i,j]:=-2;
    i:=1; e:=1;
    x[1]:=xt;
    y[1]:=yt;
    d[xt,yt]:=0;
    while i <= e do
    begin
      for j:=1 to 4 do
      begin
        xk:=x[i]+dx[j];
        yk:=y[i]+dy[j];
        if (xk > 0) and (yk > 0) and (xk <= n) and (yk <= m) then
          if d[xk,yk] = -1 then
          begin
            inc(e);
            x[e]:=xk;
            y[e]:=yk;
            d[xk,yk]:=d[x[i],y[i]]+1;
          end;
      end;
      inc(i);
    end;
    if d[xs,ys] < 0 then exit;
    for i:=1 to n do
      for j:=1 to m do was[i,j]:=False;
    e:=1;
    x[1]:=xs;
    y[1]:=ys;
    was[xs,ys]:=True;
    len:=d[xs,ys]-1;
    for q:=d[xs,ys]-1 downto 1 do
    begin
      ne:=0;
      for i:=1 to e do
        for j:=1 to 4 do
        begin
          xk:=x[i]+dx[j];
          yk:=y[i]+dy[j];
          if (xk > 0) and (yk > 0) and (xk <= n) and (yk <= m) then
            if not was[xk,yk] and (d[xk,yk] = q) then
            begin
              inc(ne);
              nx[ne]:=xk;
              ny[ne]:=yk;
              was[xk,yk]:=True;
            end;
        end;
      min:='{';
      for i:=1 to ne do
        if a[nx[i],ny[i]] < min then min:=a[nx[i],ny[i]];
      cur[len-q+1]:=min;
      e:=0;
      for i:=1 to ne do
        if a[nx[i],ny[i]] = min then
        begin
          inc(e);
          x[e]:=nx[i];
          y[e]:=ny[i];
        end;
    end;
    ok:=False;
    if len < ans then ok:=True else
    if len = ans then
      for i:=1 to len do
        if cur[i] < best[i] then
        begin
          ok:=True;
          break;
        end else
        if cur[i] > best[i] then break;
    if ok then
    begin
      ans:=len;
      for i:=1 to ans do best[i]:=cur[i];
    end;
    exit;
  end;
  if w < k then
  begin
    for i:=1 to n do
      for j:=1 to m do
        if Ord(a[i,j])-96 = v then b[i,j]:=True;
    rec(v+1,w+1);
    for i:=1 to n do
      for j:=1 to m do
        if Ord(a[i,j])-96 = v then b[i,j]:=False;
  end;
  rec(v+1,w);
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m,k);
  xs:=0; ys:=0;
  xt:=0; yt:=0;
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      read(a[i,j]);
      if a[i,j] = 'S' then
      begin
        xs:=i;
        ys:=j;
      end;
      if a[i,j] = 'T' then
      begin
        xt:=i;
        yt:=j;
      end;
    end;
    readln;
  end;
  fillchar(b,sizeof(b),False);
  b[xs,ys]:=True;
  b[xt,yt]:=True;
  ans:=maxlongint;
  rec(1,0);
  if ans = maxlongint then writeln(-1) else
  begin
    for i:=1 to ans do write(best[i]);
    writeln;
  end;
  close(input);
  close(output);
end.
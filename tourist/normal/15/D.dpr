{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  s,mat,dr,dl,ur,ul: array [0..1010,0..1010] of longint;
  f: array [0..1010,0..1010] of int64;
  rh,rw: array [0..1010] of boolean;
  tx,ty,ka,xx,yy,v,min,n,m,h,w,i,j,ke: longint;
  sum: int64;
  ae,e: array [0..1000010] of int64;
  ax,ay,x,y: array [0..1000010] of longint;

procedure Sort(l,r:longint);
var
  i,j,pp,x2,x3,tmp: longint;
  x1,tt: int64;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x1:=e[pp]; x2:=x[pp]; x3:=y[pp];
  repeat
    while (e[i] < x1) or (e[i] = x1) and ((x[i] < x2) or (x[i] = x2) and (y[i] < x3)) do inc(i);
    while (e[j] > x1) or (e[j] = x1) and ((x[j] > x2) or (x[j] = x2) and (y[j] > x3)) do dec(j);
    if i <= j then
    begin
      tt:=e[i]; e[i]:=e[j]; e[j]:=tt;
      tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
      tmp:=y[i]; y[i]:=y[j]; y[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure modify(a,b,c:longint);
var
  x,y: longint;
begin
  x:=a;
  while x <= n do
  begin
    y:=b;
    while y <= m do
    begin
      inc(s[x,y],c);
      y:=(y or (y-1))+1;
    end;
    x:=(x or (x-1))+1;
  end;
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,h,w);
  for i:=1 to n do
    for j:=1 to m do read(mat[i,j]);
  for i:=0 to n do rh[i]:=i mod h = 0;
  for i:=0 to m do rw[i]:=i mod w = 0;
  rh[n]:=True; rw[m]:=True;
  for i:=n downto 1 do
    for j:=m downto 1 do
    begin
      dr[i,j]:=mat[i,j];
      if (not rh[i]) and (dr[i+1,j] < dr[i,j]) then dr[i,j]:=dr[i+1,j];
      if (not rw[j]) and (dr[i,j+1] < dr[i,j]) then dr[i,j]:=dr[i,j+1];
    end;
  for i:=1 to n do
    for j:=m downto 1 do
    begin
      ur[i,j]:=mat[i,j];
      if (not rh[i-1]) and (ur[i-1,j] < ur[i,j]) then ur[i,j]:=ur[i-1,j];
      if (not rw[j]) and (ur[i,j+1] < ur[i,j]) then ur[i,j]:=ur[i,j+1];
    end;
  for i:=n downto 1 do
    for j:=1 to m do
    begin
      dl[i,j]:=mat[i,j];
      if (not rh[i]) and (dl[i+1,j] < dl[i,j]) then dl[i,j]:=dl[i+1,j];
      if (not rw[j-1]) and (dl[i,j-1] < dl[i,j]) then dl[i,j]:=dl[i,j-1];
    end;
  for i:=1 to n do
    for j:=1 to m do
    begin
      ul[i,j]:=mat[i,j];
      if (not rh[i-1]) and (ul[i-1,j] < ul[i,j]) then ul[i,j]:=ul[i-1,j];
      if (not rw[j-1]) and (ul[i,j-1] < ul[i,j]) then ul[i,j]:=ul[i,j-1];
    end;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=1 to m do f[i,j]:=f[i-1,j]+f[i,j-1]-f[i-1,j-1]+mat[i,j];
  ke:=0;
  for i:=1 to n-h+1 do
    for j:=1 to m-w+1 do
    begin
      sum:=f[i+h-1,j+w-1]-f[i-1,j+w-1]-f[i+h-1,j-1]+f[i-1,j-1];
      min:=dr[i,j];
      if ur[i+h-1,j] < min then min:=ur[i+h-1,j];
      if dl[i,j+w-1] < min then min:=dl[i,j+w-1];
      if ul[i+h-1,j+w-1] < min then min:=ul[i+h-1,j+w-1];
      inc(ke);
      e[ke]:=sum-int64(min)*h*w;
      x[ke]:=i;
      y[ke]:=j;
    end;
  Sort(1,ke);
  fillchar(s,sizeof(s),0);
  ka:=0;
  for i:=1 to ke do
  begin
    v:=0;
    xx:=x[i];
    while xx > 0 do
    begin
      yy:=y[i];
      while yy > 0 do
      begin
        inc(v,s[xx,yy]);
        yy:=yy and (yy-1);
      end;
      xx:=xx and (xx-1);
    end;
    if v = 0 then
    begin
      inc(ka);
      ae[ka]:=e[i];
      ax[ka]:=x[i];
      ay[ka]:=y[i];
      tx:=x[i]-h+1;
      ty:=y[i]-w+1;
      if tx < 1 then tx:=1;
      if ty < 1 then ty:=1;
      modify(tx,ty,1);
      tx:=x[i]+h;
      ty:=y[i]-w+1;
      if ty < 1 then ty:=1;
      if tx <= n then modify(tx,ty,-1);
      tx:=x[i]-h+1;
      ty:=y[i]+w;
      if tx < 1 then tx:=1;
      if ty <= m then modify(tx,ty,-1);
      tx:=x[i]+h;
      ty:=y[i]+w;
      if (tx <= n) and (ty <= m) then modify(tx,ty,1);
    end;
  end;
  writeln(ka);
  for i:=1 to ka do writeln(ax[i],' ',ay[i],' ',ae[i]);
  close(input);
  close(output);
end.
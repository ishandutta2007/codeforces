{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  n,m,i,j,ii,jj,cnt: longint;
  ft: int64;
  good: array [0..260] of boolean;
  f,t,u: array [0..260] of int64;
  c: array [0..1010,0..1010] of char;
  v,h: array [0..260,0..260] of boolean;
begin
  readln(n,m);
  for i:=1 to 4*n+1 do
  begin
    for j:=1 to 4*m+1 do read(c[i,j]);
    readln;
  end;
  for i:=1 to n do
    for j:=1 to m do
    begin
      cnt:=0;
      for ii:=i*4-2 to i*4 do
        for jj:=j*4-2 to j*4 do
          if c[ii,jj] = 'O' then inc(cnt);
      h[i,j]:=True;
      v[i,j]:=True;
      if (cnt = 2) or (cnt = 3) then
        if c[i*4,j*4] = 'O' then v[i,j]:=False
        else h[i,j]:=False;
      if cnt = 6 then
        if c[i*4,j*4-1] = 'O' then v[i,j]:=False
        else h[i,j]:=False;
    end;
  for j:=1 to m do
    if n and 1 = 1 then good[j]:=False else
    begin
      good[j]:=True;
      for i:=1 to n do
        if not v[i,j] then good[j]:=False;
    end;
  for j:=1 to m-1 do
  begin
    t[0]:=1;
    for i:=1 to n do
    begin
      t[i]:=0;
      if h[i,j] and h[i,j+1] then t[i]:=t[i-1];
      if (i > 1) and v[i,j] and v[i,j+1] and
                     v[i-1,j] and v[i-1,j+1] then
      begin
        inc(t[i],t[i-2]);
        if t[i] >= md then dec(t[i],md);
      end;
    end;
    u[j+1]:=t[n];
    if good[j] and good[j+1] then
    begin
      dec(u[j+1]);
      if u[j+1] < 0 then inc(u[j+1],md);
    end;
  end;
  f[0]:=1;
  for j:=1 to m do
  begin
    f[j]:=0;
    if good[j] then f[j]:=f[j-1];
    if j > 1 then
    begin
      ft:=int64(u[j])*f[j-2] mod md;
      inc(f[j],ft);
      if f[j] >= md then dec(f[j],md);
    end;
  end;
  writeln(f[m]);
end.
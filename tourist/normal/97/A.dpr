{$R-,S-,Q-,I-,O+}
var
  n,m,i,j,k,p,ans: longint;
  ok: boolean;
  used,col,ss,ff,bc: array [0..4444] of longint;
  c: array [0..33,0..33] of char;
  w,q: array [0..33,0..33] of longint;

procedure rec(v:longint);
var
  i,j,c1,c2,tmp: longint;
begin
  if v = k+1 then
  begin
    for i:=1 to 7 do
      for j:=i to 7 do w[i,j]:=0;
    ok:=True;
    for i:=1 to p do
    begin
      c1:=col[ss[i]];
      c2:=col[ff[i]];
      if c1 > c2 then
      begin
        tmp:=c1; c1:=c2; c2:=tmp;
      end;
      if w[c1,c2] = 0 then w[c1,c2]:=1 else
      begin
        ok:=False;
        break;
      end;
    end;
    if ok then
    begin
      inc(ans);
      for i:=1 to k do bc[i]:=col[i];
    end;
    exit;
  end;
  for i:=1 to 7 do
  begin
    if used[i] < 2 then
    begin
      col[v]:=i;
      inc(used[i]);
      rec(v+1);
      dec(used[i]);
      col[v]:=0;
    end;
    if used[i] = 0 then break;
  end;
end;

begin
  readln(n,m);
  fillchar(c,sizeof(c),'.');
  for i:=1 to n do
  begin
    for j:=1 to m do read(c[i,j]);
    readln;
  end;
  fillchar(q,sizeof(q),0);
  k:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (q[i,j] = 0) and (c[i,j] <> '.') then
      begin
        inc(k);
        q[i,j]:=k;
        q[i+1,j]:=k;
        q[i,j+1]:=k;
        q[i+1,j+1]:=k;
      end;
  p:=0;
  for i:=1 to n do
    for j:=1 to m do
      if c[i,j] = '.' then continue else
      if c[i+1,j] = c[i,j] then
      begin
        inc(p);
        ss[p]:=q[i,j];
        ff[p]:=q[i+1,j];
      end else
      if c[i,j] = c[i,j+1] then
      begin
        inc(p);
        ss[p]:=q[i,j];
        ff[p]:=q[i,j+1];
      end;
  for i:=1 to 7 do used[i]:=0;
  for i:=1 to k do col[i]:=0;
  ans:=0;
  rec(1);
  writeln(int64(ans)*5040);
  for i:=1 to n do
  begin
    for j:=1 to m do
      if c[i,j] = '.' then write('.')
      else write(bc[q[i,j]]-1);
    writeln;
  end;
end.
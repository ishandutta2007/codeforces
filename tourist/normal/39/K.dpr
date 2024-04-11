{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  ans: int64;
  g,ii,jj,kx,tmp,cur,n,m,k,i,j,p,nx,q1,q2,i1,i2: longint;
  ch: char;
  a: array [0..1010,0..1010] of char;
  good,clear: array [0..1010] of boolean;
  cnt,x,xx,tx,x1,y1,x2,y2: array [0..1010] of longint;
  w: array [-10..1010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(ch);
      while not (ch in ['.','*']) do read(ch);
      a[i,j]:=ch;
    end;
  p:=0;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] = '*' then
      begin
        inc(p);
        x1[p]:=i; y1[p]:=j;
        x2[p]:=i; y2[p]:=j;
        for ii:=i+1 to n do
          if a[ii,j] = '*' then inc(x2[p])
          else break;
        for jj:=j+1 to m do
          if a[i,jj] = '*' then inc(y2[p])
          else break;
        for ii:=x1[p] to x2[p] do
          for jj:=y1[p] to y2[p] do a[ii,jj]:='.';
      end;
  kx:=2;
  x[1]:=0; x[2]:=n;
  for i:=1 to p do
  begin
    inc(kx);
    x[kx]:=x1[i]-1;
    inc(kx);
    x[kx]:=x2[i];
  end;
  for i:=1 to kx-1 do
    for j:=i+1 to kx do
      if x[i] > x[j] then
      begin
        tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
      end;
  nx:=0; xx[0]:=-1;
  for i:=1 to kx do
    if x[i] > xx[nx] then
    begin
      if x[i] > xx[nx]+1 then
      begin
        inc(nx);
        xx[nx]:=xx[nx-1]+1;
        tx[nx]:=x[i]-xx[nx-1]-1;
      end;
      inc(nx);
      xx[nx]:=x[i];
      tx[nx]:=1;
    end;
  ans:=0;
  for q1:=1 to nx do
    for q2:=q1+1 to nx do
    begin
      i1:=xx[q1]; i2:=xx[q2];
      for j:=0 to m do good[j]:=True;
      for j:=0 to m do clear[j]:=False;
      for j:=0 to m do cnt[j]:=0;
      for j:=1 to p do
        if (x1[j] > i1) and (x2[j] <= i2) then
        begin
          inc(cnt[y2[j]]);
          for i:=y1[j] to y2[j]-1 do good[i]:=False;
        end else
        if (x1[j] <= i1) and (x2[j] > i1) or (x1[j] <= i2) and (x2[j] > i2) then
        begin
          for i:=y1[j] to y2[j]-1 do good[i]:=False;
          clear[y2[j]]:=True;
        end;
      for j:=0 to m-1 do inc(cnt[j+1],cnt[j]);
      for j:=-3 to p do w[j]:=0;
      cur:=0; g:=0;
      for j:=0 to m do
      begin
        if clear[j] then
        begin
          for i:=g to j do w[cnt[i]]:=0;
          g:=j;
        end;
        if good[j] then
        begin
          inc(cur,w[cnt[j]-3]+w[cnt[j]-2]+w[cnt[j]-1]);
          inc(w[cnt[j]]);
        end;
      end;
      ans:=ans+int64(cur)*tx[q1]*tx[q2];
    end;
  writeln(ans);
  close(input);
  close(output);
end.
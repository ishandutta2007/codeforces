{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,xx,yy,kx,tmp,j,t,q,ii: longint;
  num,len,pg,g,f,a,b,x,px,last,pred,kf: array [0..10010] of longint;
  need: array [0..10010] of boolean;
  qf: array [0..2010,0..2010] of longint;

procedure go(x:longint);
var
  j: longint;
begin
  need[num[x]]:=True;
  for j:=1 to kf[x] do go(qf[x,j]);
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(xx,yy);
    a[i]:=xx-yy;
    b[i]:=xx+yy;
  end;
  kx:=0;
  for i:=1 to n do
  begin
    inc(kx);
    x[kx]:=a[i];
    px[kx]:=i;
    inc(kx);
    x[kx]:=b[i];
    px[kx]:=-i;
  end;
  for i:=1 to kx-1 do
    for j:=i+1 to kx do
      if x[i] > x[j] then
      begin
        tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
        tmp:=px[i]; px[i]:=px[j]; px[j]:=tmp;
      end;
  t:=0;
  for i:=1 to kx do
  begin
    if (i = 1) or (x[i] <> x[i-1]) then inc(t);
    if px[i] > 0 then a[px[i]]:=t
    else b[-px[i]]:=t;
  end;
  inc(t);
  inc(n);
  a[n]:=1;
  b[n]:=t+1;
  for i:=1 to n do
  begin
    num[i]:=i;
    len[i]:=b[i]-a[i];
  end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if len[i] > len[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
        tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
        tmp:=num[i]; num[i]:=num[j]; num[j]:=tmp;
        tmp:=len[i]; len[i]:=len[j]; len[j]:=tmp;
      end;
  fillchar(last,sizeof(last),0);
  for i:=1 to n do
  begin
    pred[i]:=last[a[i]];
    last[a[i]]:=i;
  end;
  for ii:=1 to n do
  begin
    for q:=a[ii] to b[ii] do
    begin
      g[q]:=0;
      pg[q]:=0;
    end;
    for q:=a[ii] to b[ii] do
    begin
      j:=last[q];
      while j > 0 do
      begin
        if (b[j] <= b[ii]) and (j < ii) then
          if g[q]+f[j] > g[b[j]] then
          begin
            g[b[j]]:=g[q]+f[j];
            pg[b[j]]:=j;
          end;
        j:=pred[j];
      end;
      if g[q] > g[q+1] then
      begin
        g[q+1]:=g[q];
        pg[q+1]:=0;
      end;
    end;
    f[ii]:=g[b[ii]]+1;
    kf[ii]:=0;
    q:=b[ii];
    while q > a[ii] do
      if pg[q] = 0 then dec(q) else
      begin
        inc(kf[ii]);
        qf[ii,kf[ii]]:=pg[q];
        q:=a[pg[q]];
      end;
  end;
  writeln(f[n]-1);
  fillchar(need,sizeof(need),False);
  go(n);
  for i:=1 to n-1 do
    if need[i] then
    begin
      write(i);
      dec(f[n]);
      if f[n] > 1 then write(' ');
    end;
  writeln;
  close(input);
  close(output);
end.
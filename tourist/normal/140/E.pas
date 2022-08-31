{$R-,S-,Q-,I-,O+}
var
  cc,kp,ans,ii,tot,ft,n,m,md,i,max,j: longint;
  f: array [0..5050,0..5050] of longint;
  fact,g,ng,c: array [0..5050] of longint;
  h,t,id,p,a,b: array [0..1000010] of longint;

procedure build(x,l,r:longint);
begin
  t[x]:=1;
  h[x]:=0;
  if l < r then
  begin
    build(x+x,l,(l+r) shr 1);
    build(x+x+1,(l+r) shr 1+1,r);
  end;
end;

procedure modify(x,l,r,z,v:longint);
var
  j: longint;
begin
  if l = r then
  begin
    inc(h[x],v);
    t[x]:=1;
    for j:=1 to h[x] do t[x]:=int64(t[x])*p[l] mod md;
  end else
  begin
    if z <= (l+r) shr 1 then modify(x+x,l,(l+r) shr 1,z,v)
    else modify(x+x+1,(l+r) shr 1+1,r,z,v);
    t[x]:=int64(t[x+x])*t[x+x+1] mod md;
  end;
end;

procedure doit(u,v:longint);
begin
  while u > 1 do
  begin
    modify(1,1,kp,id[b[u]],v);
    u:=u div b[u];
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,md);
  for i:=1 to m do b[i]:=i;
  for i:=2 to 1000 do
    if b[i] = i then
    begin
      cc:=i*i;
      while cc <= m do
      begin
        if b[cc] = cc then b[cc]:=i;
        inc(cc,i);
      end;
    end;
  kp:=0;
  for i:=2 to m do
    if b[i] = i then
    begin
      inc(kp);
      p[kp]:=i;
      id[i]:=kp;
    end;
  max:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i] > max then max:=a[i];
  end;
  fillchar(f,sizeof(f),0);
  f[1,1]:=1;
  for i:=1 to max-1 do
    for j:=1 to max-1 do
      if f[i,j] > 0 then
      begin
        f[i+1,j]:=(f[i+1,j]+int64(f[i,j])*(j-1)) mod md;
        f[i+1,j+1]:=f[i+1,j+1]+f[i,j];
        if f[i+1,j+1] >= md then dec(f[i+1,j+1],md);
      end;
  fact[0]:=1;
  for i:=1 to max do fact[i]:=int64(fact[i-1])*i mod md;
  build(1,1,kp);
  c[0]:=1;
  for i:=1 to max do
    if i > m then c[i]:=0 else
    begin
      doit(m-i+1,1);
      doit(i,-1);
      c[i]:=t[1];
    end;
  fillchar(g,sizeof(g),0);
  a[0]:=0; g[0]:=1;
  for ii:=1 to n do
  begin
    tot:=0;
    for i:=0 to a[ii-1] do
    begin
      tot:=tot+g[i];
      if tot >= md then dec(tot,md);
    end;
    ng[0]:=0;
    for i:=1 to a[ii] do
    begin
      ft:=int64(c[i])*f[a[ii],i] mod md;
      ft:=int64(ft)*fact[i] mod md;
      ft:=int64(ft)*tot mod md;
      if i <= a[ii-1] then ft:=(ft-int64(g[i])*fact[i] mod md*f[a[ii],i]) mod md;
      if ft < 0 then inc(ft,md);
      ng[i]:=ft;
    end;
    for i:=0 to a[ii] do g[i]:=ng[i];
  end;
  ans:=0;
  for i:=0 to a[n] do ans:=(ans+g[i]) mod md;
  writeln(ans);
//  close(input);
//  close(output);
end.
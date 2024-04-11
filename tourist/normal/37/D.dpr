{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  step,q,n,m,i,j,jj,lg,v,k,tot,ans: longint;
  f: array [0..110,0..10010] of int64;
  g: array [0..10010,0..110] of longint;
  inv: array [0..10010] of longint;
  x,y: array [0..110] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(m);
  for i:=1 to m do read(x[i]);
  for i:=1 to m do read(y[i]);
  n:=0;
  for i:=1 to m do inc(n,x[i]);
  for i:=1 to n do
  begin
    step:=1 shl 30; q:=1;
    while step > 0 do
    begin
      q:=int64(q)*q mod md;
      if step and (md-2) <> 0 then q:=int64(q)*i mod md;
      step:=step shr 1;
    end;
    inv[i]:=q;
  end;
  for k:=0 to n do
  begin
    v:=1;
    for q:=k downto k-100 do
    begin
      g[k,k-q]:=v;
      v:=((int64(v)*q) mod md*inv[k-q+1]) mod md;
    end;
  end;
  fillchar(f,sizeof(f),0);
  f[1,0]:=1; tot:=0;
  for i:=1 to m do
  begin
    for j:=0 to tot do
    begin
      f[i,j]:=f[i,j] mod md;
      jj:=j+x[i];
      lg:=jj-y[i];
      if lg < 0 then lg:=0;
      for k:=jj downto lg do
      begin
        f[i+1,k]:=(f[i+1,k]+int64(f[i,j])*g[jj,jj-k]);
        if f[i+1,k] > 8e18 then f[i+1,k]:=f[i+1,k] mod md;
      end;
    end;
    inc(tot,x[i]);
  end;
  ans:=f[m+1,0] mod md;
  for i:=1 to n do ans:=(int64(ans)*i) mod md;
  for i:=1 to m do
    for j:=1 to x[i] do ans:=(int64(ans)*inv[j]) mod md;
  writeln(ans);
  close(input);
  close(output);
end.
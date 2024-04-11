{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  ans: int64;
  ii,n,k,m,i,kw,j: longint;
  pv,w,ss,ff,pred,last: array [0..200010] of longint;
  was: array [0..200010] of boolean;
  f: array [0..50010,0..510] of longint;

procedure rec(v:longint);
var
  j,q: longint;
begin
  inc(kw);
  w[kw]:=v;
  was[v]:=True;
  for q:=1 to k do f[v,q]:=0;
  f[v,0]:=1;
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      pv[ff[j]]:=v;
      rec(ff[j]);
      for q:=1 to k do f[v,q]:=f[v,q]+f[ff[j],q-1];
    end;
    j:=pred[j];
  end;
end;

begin
  read(n,k);
  m:=n-1;
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  fillchar(f,sizeof(f),0);
  pv[1]:=0;
  rec(1);
  for ii:=2 to n do
  begin
    i:=w[ii];
    for j:=k downto 1 do
    begin
      f[i,j]:=f[i,j]+f[pv[i],j-1];
      if j > 1 then f[i,j]:=f[i,j]-f[i,j-2];
    end;
  end;
  ans:=0;
  for i:=1 to n do ans:=ans+f[i,k];
  writeln(ans div 2);
end.
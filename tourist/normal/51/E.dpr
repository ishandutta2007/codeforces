{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,m,i,j,k,e,x,y,z: longint;
  ans: int64;
  a,b: array [0..710,0..710] of longint;
  deg: array [0..710] of longint;
  ss,ff: array [0..500010] of longint;
begin
  read(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    a[ss[i],ff[i]]:=1;
    a[ff[i],ss[i]]:=1;
  end;
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to n do
        if a[i,j]+a[j,k] = 2 then inc(b[i,k]);
  fillchar(deg,sizeof(deg),0);
  for i:=1 to n do
    for j:=1 to n do inc(deg[i],a[i,j]);
  ans:=0;
  for e:=1 to m do
  begin
    x:=ss[e]; y:=ff[e];
    for z:=1 to n do
      if (x <> z) and (y <> z) then
      begin
        inc(ans,b[x,z]*b[y,z]);
        if a[x,z] = 1 then dec(ans,b[x,z]);
        if a[y,z] = 1 then dec(ans,b[y,z]);
        if (a[x,z] = 1) and (a[y,z] = 1) then inc(ans);
      end;
    for i:=1 to n do
      if a[x,i]+a[i,y] = 2 then dec(ans,deg[i]-2);
  end;
  writeln(ans div 5);
end.
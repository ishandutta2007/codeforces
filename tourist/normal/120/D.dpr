{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,i,j,x,p1,p2,p3,k1,k2,k3,ans,k: longint;
  r,c: array [0..10010] of longint;

procedure swap(var a,b:longint);
var
  c: longint;
begin
  c:=a; a:=b; b:=c;
end;

begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  read(n,m);
  fillchar(r,sizeof(r),0);
  fillchar(c,sizeof(c),0);
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(x);
      inc(r[i],x);
      inc(c[j],x);
    end;
  read(p1,p2,p3);
  if p1 > p2 then swap(p1,p2);
  if p1 > p3 then swap(p1,p3);
  if p2 > p3 then swap(p2,p3);
  ans:=0;
  for i:=1 to n-2 do
    for j:=i+1 to n-1 do
    begin
      k1:=0; k2:=0; k3:=0;
      for k:=1 to i do inc(k1,r[k]);
      for k:=i+1 to j do inc(k2,r[k]);
      for k:=j+1 to n do inc(k3,r[k]);
      if k1 > k2 then swap(k1,k2);
      if k1 > k3 then swap(k1,k3);
      if k2 > k3 then swap(k2,k3);
      if (k1 = p1) and (k2 = p2) and (k3 = p3) then inc(ans);
    end;
  for i:=1 to m-2 do
    for j:=i+1 to m-1 do
    begin
      k1:=0; k2:=0; k3:=0;
      for k:=1 to i do inc(k1,c[k]);
      for k:=i+1 to j do inc(k2,c[k]);
      for k:=j+1 to m do inc(k3,c[k]);
      if k1 > k2 then swap(k1,k2);
      if k1 > k3 then swap(k1,k3);
      if k2 > k3 then swap(k2,k3);
      if (k1 = p1) and (k2 = p2) and (k3 = p3) then inc(ans);
    end;
  writeln(ans);
  close(input);
  close(output);
end.
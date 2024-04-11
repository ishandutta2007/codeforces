{$R-,S-,Q-,I-,O+}
var
  n,u,r,i: longint;
  ans: int64;
  a,b,k,p: array [0..33] of longint;

procedure rec(v,w:longint);
var
  i: longint;
  sum: int64;
  old: array [0..33] of longint;
begin
  if v and 1 = (u+1) and 1 then
  begin
    sum:=0;
    for i:=1 to n do sum:=sum+int64(a[i])*k[i];
    if sum > ans then ans:=sum;
    if v = u+1 then exit;
  end;
  if w <> 1 then
  begin
    for i:=1 to n do a[i]:=a[i] xor b[i];
    rec(v+1,1);
    for i:=1 to n do a[i]:=a[i] xor b[i];
  end;
  for i:=1 to n do old[i]:=a[i];
  for i:=1 to n do a[i]:=old[p[i]]+r;
  rec(v+1,2);
  for i:=1 to n do a[i]:=old[i];
end;

begin
  read(n,u,r);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do read(k[i]);
  for i:=1 to n do read(p[i]);
  ans:=-round(1e12);
  rec(1,0);
  writeln(ans);
end.
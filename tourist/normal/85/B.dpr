{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  k,t: array [0..4] of int64;
  a,c,free: array [0..100010] of int64;
  u,q,n,i: longint;
  ans: int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(k[1],k[2],k[3],t[1],t[2],t[3],n);
  for i:=1 to n do
  begin
    read(c[i]);
    a[i]:=c[i];
  end;
  for q:=1 to 3 do
  begin
    fillchar(free,sizeof(free),0);
    u:=1;
    for i:=1 to n do
    begin
      if free[u] > a[i] then a[i]:=free[u];
      a[i]:=a[i]+t[q];
      free[u]:=a[i];
      inc(u);
      if u > k[q] then u:=1;
    end;
  end;
  ans:=0;
  for i:=1 to n do
    if a[i]-c[i] > ans then ans:=a[i]-c[i];
  writeln(ans);
  close(input);
  close(output);
end.
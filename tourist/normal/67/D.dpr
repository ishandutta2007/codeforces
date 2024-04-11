{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  u,n,i,x,ans: longint;
  f,p,a,m: array [0..1000010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(u);
    p[u]:=i;
  end;
  for i:=1 to n do
  begin
    read(u);
    a[p[u]]:=i;
  end;
  fillchar(m,sizeof(m),0);
  ans:=0;
  for i:=n downto 1 do
  begin
    f[i]:=0;
    x:=a[i];
    while x > 0 do
    begin
      if m[x] > f[i] then f[i]:=m[x];
      x:=x and (x-1);
    end;
    inc(f[i]);
    if f[i] > ans then ans:=f[i];
    x:=a[i];
    while x <= n do
    begin
      if f[i] > m[x] then m[x]:=f[i];
      x:=(x or (x-1))+1;
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
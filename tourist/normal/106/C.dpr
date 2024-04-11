{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,c0,d0,i,j,k,ans: longint;
  c,d,a,b,f: array [0..10010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,c0,d0);
  for i:=1 to m do
  begin
    read(a[i],b[i],c[i],d[i]);
    a[i]:=a[i] div b[i];
  end;
  fillchar(f,sizeof(f),0);
  for j:=0 to n-c0 do
    if f[j]+d0 > f[j+c0] then f[j+c0]:=f[j]+d0;
  for i:=1 to m do
    for j:=n downto 0 do
      for k:=1 to (n-j) div c[i] do
        if k > a[i] then break else
        if f[j]+k*d[i] > f[j+c[i]*k] then
          f[j+c[i]*k]:=f[j]+k*d[i];
  ans:=0;
  for i:=0 to n do
    if f[i] > ans then ans:=f[i];
  writeln(ans);
  close(input);
  close(output);
end.
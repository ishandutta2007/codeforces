{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
var
  mask,n,i,j,cr,res,m:longint;
  s:array[0..200500]of string[30];
  f:array[0..21,0..1 shl 21]of longint;
  t,st:array[0..200500]of longint;

begin
  readln(n);
  for i:=1 to n do readln(s[i]);
  m:=length(s[1]);
  for i:=2 to n do begin
    j:=m;
    while (copy(s[i-1],m-j+1,j)<>copy(s[i],1,j))do dec(j);
    t[i]:=j;
  end;
  st[1]:=m;
  for i:=2 to n do st[i]:=st[i-1]+m-t[i];
  res:=st[n];
  for i:=1 to m do 
    for j:=0 to 1 shl (m+1) do f[i][j]:=inf;
  f[0][0]:=inf;
  for i:=2 to n do begin
    cr:=m;
    if (f[0][0]+m<cr)then cr:=f[0][0]+m;
    mask:=0;
    for j:=1 to m do begin
      mask:=mask shl 1+ord(s[i][j])-48;
      if (f[j][mask]+m-j<cr)then cr:=f[j][mask]+m-j;
    end;
    cr:=cr+st[i-1];
    if (cr+st[n]-st[i]<res)then res:=cr+st[n]-st[i];
    cr:=cr-st[i];
    if (cr<f[0][0])then f[0][0]:=cr;
    mask:=0;
    for j:=1 to m do begin
      if (s[i-1][m-j+1]='1')then mask:=mask+(1 shl (j-1));
      if (cr<f[j][mask])then f[j][mask]:=cr;
    end;
  end;
  writeln(res);
end.
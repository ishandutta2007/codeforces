{$r-,q-,s-,i-,o+}
const
  MAXN=100100;
  INF=1000000000;
var
  s:ansistring;
  w,x,y,tt,n,i,j,k,min,res:longint;
  c1,c2:char;
  a,b,c:array[1..MAXN]of longint;
  d:array[1..30,1..30]of longint;
  procedure bad;
    begin
      writeln(-1);
      halt(0);
    end;
begin
  readln(s);
  n:=length(s);
  for i:=1 to n do a[i]:=ord(s[i])-96;
  readln(s);
  if (length(s)<>n)then bad;
  for i:=1 to n do b[i]:=ord(s[i])-96;
  for i:=1 to 26 do for j:=1 to 26 do d[i][j]:=INF;
  readln(tt);
  while (tt>0)do begin
    dec(tt);
    readln(c1,c2,c2,w);
    x:=ord(c1)-96;
    y:=ord(c2)-96;
    if (w<d[x][y])then d[x][y]:=w;
  end;
  for i:=1 to 26 do d[i][i]:=0;
  for k:=1 to 26 do
    for i:=1 to 26 do
      for j:=1 to 26 do
        if (d[i][k]+d[k][j]<d[i][j])
          then d[i][j]:=d[i][k]+d[k][j];
  res:=0;
  for i:=1 to n do begin
    min:=INF;
    for j:=1 to 26 do
      if (d[a[i]][j]+d[b[i]][j]<min)
        then begin
          min:=d[a[i]][j]+d[b[i]][j];
          c[i]:=j;
        end;
    if (min=INF)then bad;
    inc(res,min);
  end;
  writeln(res);
  for i:=1 to n do write(chr(c[i]+96));
end.
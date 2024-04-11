{$r-,q-,s-,i-,o+}
{$M 10000000}
uses
  math;
const
  MAXN=500500;
var
  f:array[0..MAXN,0..22]of int64;
  a:array[0..MAXN]of int64;
  b2,b,c:array[0..MAXN]of longint;
  lg2:array[0..MAXN]of longint;
  j,y,q,i,n,x:longint;
  o,tmp:int64;
  rev:boolean;
  r:array[0..MAXN]of boolean;
  procedure solve;
    begin
      for i:=1 to n do a[i]:=c[i]-b[i];
      for i:=1 to n do a[i+n]:=a[i];
      for i:=2 to n+n do a[i]:=a[i-1]+a[i];
      for i:=1 to n+n do f[i][0]:=a[i];
      for j:=1 to lg2[n+n] do
        for i:=1 to n+n do
          f[i][j]:=min(f[i][j-1],f[i+1 shl (j-1)][j-1]);
      for i:=1 to n do begin
        x:=i;
        y:=i+n-2;
        q:=lg2[y-x+1];
        o:=f[x][q];
        if (f[y+1-1 shl q][q]<o)then o:=f[y+1-1 shl q][q];
        if (o-a[i-1]>=0)then begin
          if (rev)then r[n-i+1]:=true else r[i]:=true;
        end;
      end;
    end;
begin
  read(n);
  a[0]:=0;
  lg2[1]:=0;
  for i:=2 to n+n do
    lg2[i]:=lg2[i shr 1]+1;
  for i:=1 to n do read(c[i]);
  for i:=1 to n do read(b[i]);
  rev:=false;solve;
  for i:=1 to n do begin
    j:=i-1;
    if (j=0)then j:=n;
    b2[i]:=b[j];
  end;
  for i:=1 to n do b[i]:=b2[i];
  for i:=1 to n shr 1 do begin
    tmp:=c[i];c[i]:=c[n-i+1];c[n-i+1]:=tmp;
    tmp:=b[i];b[i]:=b[n-i+1];b[n-i+1]:=tmp;
  end;
  rev:=true;solve;
  x:=0;
  for i:=1 to n do
    if (r[i])then inc(x);
  writeln(x);
  for i:=1 to n do
    if (r[i])then write(i,' ');
  writeln;
end.
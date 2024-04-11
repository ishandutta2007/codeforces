{$r-,q-,s-,i-,o+}
type
  int64=qword;
const
  inf:int64=100000000000000000;
var
  f:array[0..55,0..55,0..555]of int64;
  py,px:array[0..55,0..55,0..555]of longint;
  pxx,pyy,xx,yy,q,tmp,kr,i,j,k,n,m,tk:longint;
  max,ti,tt:int64;
  r2,a,b:array[0..500500]of int64;
  r1,nom,c:array[0..500500]of longint;

begin
  read(n,m,tk);
  for i:=1 to m do read(a[i],b[i],c[i]);

  for i:=1 to m do nom[i]:=i;
  for i:=1 to m-1 do 
    for j:=1 to m-1 do
      if (c[j]>c[j+1])then begin
        ti:=a[j];a[j]:=a[j+1];a[j+1]:=ti;
        ti:=b[j];b[j]:=b[j+1];b[j+1]:=ti;
        tmp:=c[j];c[j]:=c[j+1];c[j+1]:=tmp;
        tmp:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp;
      end;

  fillchar(f,sizeof(f),$0);
  for j:=1 to m do
    for k:=0 to longint(b[j]-a[j])do
      f[1][j][k]:=k+a[j];

  for i:=1 to n-1 do
    for j:=1 to m do
      for k:=0 to longint(b[j]-a[j])do
        if (f[i][j][k]<>0)then begin
          tt:=a[j]+k+tk;
          for q:=j+1 to m do
            if (c[q]>c[j])and(tt>=a[q])and(tt<=b[q])and(f[i][j][k]+tt>f[i+1][q][longint(tt-a[q])])
              then begin
                f[i+1][q][longint(tt-a[q])]:=f[i][j][k]+tt;
                px[i+1][q][longint(tt-a[q])]:=j;
                py[i+1][q][longint(tt-a[q])]:=k;
              end;
          tt:=a[j]+k;
          if (tt>inf/tk)then continue;
          tt:=tt*tk;
          for q:=j+1 to m do
            if (c[q]>c[j])and(tt>=a[q])and(tt<=b[q])and(f[i][j][k]+tt>f[i+1][q][longint(tt-a[q])])
              then begin
                f[i+1][q][longint(tt-a[q])]:=f[i][j][k]+tt;
                px[i+1][q][longint(tt-a[q])]:=j;
                py[i+1][q][longint(tt-a[q])]:=k;
              end;
        end;

  max:=0;
  xx:=0;
  yy:=0;
  for j:=1 to m do
    for k:=0 to longint(b[j]-a[j])do
      if (f[n][j][k]>max)then begin
        max:=f[n][j][k];
        xx:=j;yy:=k;
      end;
  if (max<1)then begin
    writeln('NO');
    exit;
  end;
  kr:=0;
  writeln('YES');
  for i:=n downto 1 do begin
    inc(kr);
    r1[kr]:=nom[xx];
    r2[kr]:=a[xx]+yy;
    pxx:=px[i][xx][yy];
    pyy:=py[i][xx][yy];
    xx:=pxx;
    yy:=pyy;
  end;
  for i:=kr downto 1 do writeln(r1[i],' ',r2[i]);
end.
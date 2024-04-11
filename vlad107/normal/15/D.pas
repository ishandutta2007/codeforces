{$r-,q-,s-,i-,o+}
const
  maxcr=1000200;
  maxn=1111;
  inf=1111111111;
var
  hx,hy,r1,r2:array[0..maxcr]of longint;
  r3,hz:array[0..maxcr]of int64;
  f,fsum:array[0..maxn,0..maxn]of int64;
  fleft,fmin,a:array[0..maxn,0..maxn]of longint;
  s1,t1,s2,t2:array[0..maxn]of longint;
  kh,tmp,ka,kb,cr,n,m,ks1,ks2,i,j,xx,yy:longint;
  was:array[0..maxn,0..maxn]of boolean;
  zz:int64;
  procedure qs(l,r:longint);
    var
      tmp,i,j,xx,yy:longint;
      t2,zz:int64;
    begin
      i:=l;j:=r;
      xx:=hx[(i+j)shr 1];
      yy:=hy[(i+j)shr 1];
      zz:=hz[(i+j)shr 1];
      while (i<=j)do begin
        while (zz<hz[i])or(zz=hz[i])and(xx<hx[i])or(zz=hz[i])and(xx=hx[i])and(yy<hy[i])do inc(i);
        while (zz>hz[j])or(zz=hz[j])and(xx>hx[j])or(zz=hz[j])and(xx=hx[j])and(yy>hy[j])do dec(j);
        if (i>j)then break;
        tmp:=hx[i];hx[i]:=hx[j];hx[j]:=tmp;
        tmp:=hy[i];hy[i]:=hy[j];hy[j]:=tmp;
        t2:=hz[i];hz[i]:=hz[j];hz[j]:=t2;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,m,ka,kb);
  for i:=1 to n do 
    for j:=1 to m do read(a[i][j]);
  s1[0]:=inf;t1[0]:=inf;
  s2[0]:=inf;t2[0]:=inf;
  for i:=1 to n do begin
    ks1:=0;ks2:=0;
    for j:=1 to kb do begin
      inc(ks1);
      s1[ks1]:=a[i][j];
      t1[ks1]:=t1[ks1-1];
      if (s1[ks1]<t1[ks1])then t1[ks1]:=s1[ks1];
    end;
    fleft[i][kb]:=t1[ks1];
    for j:=kb+1 to m do begin
      if (ks2=0)then begin
        while (ks1>0)do begin
          inc(ks2);
          s2[ks2]:=s1[ks1];
          t2[ks2]:=t2[ks2-1];
          if (s2[ks2]<t2[ks2])then t2[ks2]:=s2[ks2];
          dec(ks1);
        end;
      end;
      dec(ks2);
      inc(ks1);
      s1[ks1]:=a[i][j];
      t1[ks1]:=t1[ks1-1];
      if (s1[ks1]<t1[ks1])then t1[ks1]:=s1[ks1];
      fleft[i][j]:=t1[ks1];
      if (t2[ks2]<fleft[i][j])then fleft[i][j]:=t2[ks2];
    end;
  end;
  for j:=kb to m do begin
    ks1:=0;ks2:=0;
    for i:=1 to ka do begin
      inc(ks1);
      s1[ks1]:=fleft[i][j];
      t1[ks1]:=t1[ks1-1];
      if (s1[ks1]<t1[ks1])then t1[ks1]:=s1[ks1];
    end;
    fmin[ka][j]:=t1[ks1];
    for i:=ka+1 to n do begin
      if (ks2=0)then begin
        while (ks1>0)do begin
          inc(ks2);
          s2[ks2]:=s1[ks1];
          t2[ks2]:=t2[ks2-1];
          if (s2[ks2]<t2[ks2])then t2[ks2]:=s2[ks2];
          dec(ks1);
        end;
      end;
      dec(ks2);
      inc(ks1);
      s1[ks1]:=fleft[i][j];
      t1[ks1]:=t1[ks1-1];
      if (s1[ks1]<t1[ks1])then t1[ks1]:=s1[ks1];
      fmin[i][j]:=t1[ks1];
      if (t2[ks2]<fmin[i][j])then fmin[i][j]:=t2[ks2];
    end;
  end;
  fillchar(fsum,sizeof(fsum),$0);
  for i:=1 to n do 
    for j:=1 to m do 
      fsum[i][j]:=fsum[i-1][j]+fsum[i][j-1]-fsum[i-1][j-1]+a[i][j];
  for i:=ka to n do 
    for j:=kb to m do 
      f[i-ka+1][j-kb+1]:=fsum[i][j]+fsum[i-ka][j-kb]-fsum[i-ka][j]-fsum[i][j-kb]-int64(fmin[i][j])*ka*kb;
  kh:=0;
  fillchar(was,sizeof(was),false);
  for i:=1 to n-ka+1 do 
    for j:=1 to m-kb+1 do begin
      inc(kh);
      hx[kh]:=i;
      hy[kh]:=j;
      hz[kh]:=f[i][j];
    end;
  cr:=0;
  qs(1,kh);
  while (kh>0)do begin
    xx:=hx[kh];
    yy:=hy[kh];
    zz:=hz[kh];
    dec(kh);
    if (was[xx][yy])then continue;
    inc(cr);
    r1[cr]:=xx;
    r2[cr]:=yy;
    r3[cr]:=zz;
    for i:=xx to xx+ka-1 do  
      for j:=yy to yy+kb-1 do begin
        was[i][j]:=true;
        if (i-ka+1>=1)and(j-kb+1>=1)then was[i-ka+1][j-kb+1]:=true;
        if (i-ka+1>=1)then was[i-ka+1][j]:=true;
        if (j-kb+1>=1)then was[i][j-kb+1]:=true;
      end;
  end;
  writeln(cr);
  for i:=1 to cr do writeln(r1[i],' ',r2[i],' ',r3[i]);
end.
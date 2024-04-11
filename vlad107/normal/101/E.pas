{$r-,q-,s-,i-,o+}
const
  maxr=2000;
  maxn=20500;
  maxb=maxn div maxr+10;
var 
  first:boolean;
  f,xx,yy:array[0..maxn]of longint;
  krr,tt,i,qi,qj,j,ii,jj,ni,nj,ti,tj,si,sj,n,m,base:longint;
  column,row:array[0..maxb,0..maxn]of longint;
  pf,ff:array[0..maxr+55,0..maxr+55]of longint;
  res:ansistring;
  procedure assert(x:boolean);
    begin
      if (x)then exit;
      writeln('!');
      halt(0);
    end;
begin   
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,m,base);
  krr:=maxr;
  for i:=1 to n do begin
    read(xx[i]);
    xx[i]:=xx[i] mod base;
  end;
  for i:=1 to m do begin
    read(yy[i]);
    yy[i]:=yy[i] mod base;
  end;
  fillchar(f,sizeof(f),$0);
  ii:=0; 
  for i:=1 to n do begin
    jj:=0;
    tj:=0;
    for j:=1 to m do begin
      if (f[j-1]>f[j])then f[j]:=f[j-1];
      tt:=xx[i]+yy[j];
      if (tt>=base)then dec(tt,base);
      f[j]:=f[j]+tt;
      inc(tj);
      if (tj=1)then begin
        inc(jj);
        column[jj,i]:=f[j];
      end;
      if (tj=krr)then tj:=0;
    end; 
    if (i mod krr=1)then begin
      inc(ii);
      for j:=1 to m do row[ii,j]:=f[j];
    end; 
  end;
  writeln(f[m]);
  ii:=n;jj:=m;
  res:='';
  first:=true;
  while (ii>1)and(jj>1)do begin
    ti:=(ii-1)div krr+1;
    tj:=(jj-1)div krr+1;
    si:=(ti-1)*krr+1;
    sj:=(tj-1)*krr+1;
    if (not first)then begin
      if (ii=si)then dec(ti);
      if (jj=sj)then dec(tj);
      assert((ti>0)and(ti<maxb));
      assert((tj>0)and(tj<maxb));
      si:=(ti-1)*krr+1;
      sj:=(tj-1)*krr+1;
    end else first:=false;
//    for i:=0 to ii-si+1 do for j:=0 to jj-sj+1 do ff[i][j]:=0;
    for i:=si to ii do ff[i-si+1][1]:=column[tj,i];
    for j:=sj to jj do ff[1][j-sj+1]:=row[ti,j];
    for i:=2 to ii-si+1 do 
      for j:=2 to jj-sj+1 do begin
        if (ff[i][j-1]>ff[i-1][j])then begin
          ff[i][j]:=ff[i][j-1];
          pf[i][j]:=2;
        end else begin
          ff[i][j]:=ff[i-1][j];
          pf[i][j]:=1;
        end;
        tt:=xx[i+si-1]+yy[j+sj-1];
        if (tt>=base)then dec(tt,base);
        ff[i][j]:=ff[i][j]+tt;
      end;
    qi:=ii;
    qj:=jj;
    while (qi>si)and(qj>sj)do begin
      if (pf[qi-si+1][qj-sj+1]=1)then begin
        dec(qi);
        res:=res+'C';
      end else begin
        dec(qj);
        res:=res+'S';
      end;
    end;
    ii:=qi;jj:=qj;
  end;
  while (ii>1)do begin
    res:=res+'C';
    dec(ii);
  end;
  while (jj>1)do begin
    res:=res+'S';
    dec(jj);
  end;
  for i:=length(res)downto 1 do write(res[i]);
  writeln;
end.
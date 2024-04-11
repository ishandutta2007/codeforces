{$r-,q-,s-,i-,o+}
const
  base=333;

var
  u:array[0..333,0..100500]of longint;
  kst,nm,qt,ll,rr,tmp,kq,i,j,n,m:longint;
  mm:int64;
  nx,sn,lq,rq,tq,nmax,nt,nom,x,y,a,b,l,r,t:array[0..500500]of longint;
  sx:array[0..500500]of extended;
  
  procedure qsm(ll,rr:longint);
    var
      i,j,xx,nn:longint;
    begin
      i:=ll;j:=rr;
      nn:=i+random(j-i+1);
      xx:=t[nn];
      while (i<=j)do begin
        while (xx>t[i])do inc(i);
        while (xx<t[j])do dec(j);
        if (i>j)then break;
        tmp:=l[i];l[i]:=l[j];l[j]:=tmp;
        tmp:=r[i];r[i]:=r[j];r[j]:=tmp;
        tmp:=t[i];t[i]:=t[j];t[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<rr)Then qsm(i,rr);
      if (j>ll)then qsm(ll,j);
    end;
    
  procedure qsx(l,r:longint);
    var
      i,j,nn,xx,yy:longint;
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=x[nn];
      yy:=y[nn];
      while (i<=j)do begin
        while (xx<x[i])or(xx=x[i])and(yy>y[i])do inc(i);
        while (xx>x[j])or(xx=x[j])and(yy<y[j])do dec(j);
        if (i>j)then break;
        tmp:=x[i];x[i]:=x[j];x[j]:=tmp;
        tmp:=y[i];y[i]:=y[j];y[j]:=tmp;
        tmp:=nx[i];nx[i]:=nx[j];nx[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qsx(i,r);
      if (j>l)then qsx(l,j);
    end;
    
  procedure solve;
    var
      mq,j,i:longint;
      tu:extended;
    begin
      for i:=1 to kq do nx[i]:=i;
      qsx(1,kq);
      kst:=1;sx[1]:=0;sn[1]:=1;
      mq:=y[1];
      for i:=2 to kq do begin
        if (mq>=y[i])then continue;
        mq:=y[i];
        while (kst>1)do begin
          j:=sn[kst];
          tu:=(x[j]-x[i])/(y[i]-y[j]);
          if (tu>sx[kst])then break;
          dec(kst);
        end;
        j:=sn[kst];
        inc(kst);
        sx[kst]:=(x[j]-x[i])/(y[i]-y[j]);
        sn[kst]:=i;
      end;
      j:=1;
      for i:=1 to m do begin
        while (j<kst)and(t[i]>sx[j+1])do inc(j);
        nmax[i]:=nx[sn[j]];
      end;
{      
      for i:=1 to m do begin
        max[i]:=-1;
        nmax[i]:=0;
        for j:=1 to kq do 
          if (x[j]+y[j]*t[i]>max[i])then begin
            max[i]:=x[j]+y[j]*t[i];
            nmax[i]:=j;
          end;
      end;
}
    end;
    
  procedure upd(i,t:longint;var mm:int64;var nm:longint);
    begin
      if (a[i]+int64(b[i])*t>mm)then begin
        mm:=a[i]+int64(b[i])*t;
        nm:=i;
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m);
  for i:=1 to n do read(a[i],b[i]);
  for i:=1 to m do read(l[i],r[i],t[i]);
  for i:=1 to m do begin
    lq[i]:=l[i];rq[i]:=r[i];tq[i]:=t[i];
  end;
  for i:=1 to m do nom[i]:=i;
  qsm(1,m);
  nt[0]:=0;
  for i:=1 to n do begin
    nt[i]:=nt[i-1];
    if ((i-1)mod base=0)then inc(nt[i]);
  end;
  for i:=1 to n do 
    if (nt[i]<>nt[i-1])then begin
      kq:=1;j:=i;
      x[1]:=a[i];y[1]:=b[i];
      while (nt[j+1]=nt[j])do begin
        inc(j);inc(kq);
        x[kq]:=a[j];y[kq]:=b[j];
      end;
      solve;
      for j:=1 to m do u[nt[i],nom[j]]:=i+nmax[j]-1;
    end;
{
  for i:=1 to nt[n] do begin
    for j:=1 to m do write(u[i][j],' ');
    writeln;
  end;
}
  for i:=1 to m do begin
    l[i]:=lq[i];r[i]:=rq[i];t[i]:=tq[i];
  end;
  for i:=1 to m do begin
    ll:=l[i];rr:=r[i];
    if (nt[ll]=nt[rr])then begin
      mm:=-1;nm:=0;
      for j:=ll to rr do 
        if (a[j]+int64(b[j])*t[i]>mm)then begin
          mm:=a[j]+int64(b[j])*t[i];
          nm:=j;
        end;
      writeln(nm);
      continue;
    end;
    mm:=-1;nm:=0;
    for j:=nt[ll]+1 to nt[rr]-1 do begin
      qt:=u[j][i];
      upd(qt,t[i],mm,nm);
    end;
    j:=ll;
    while (nt[j]=nt[ll])do begin
      upd(j,t[i],mm,nm);
      inc(j);
    end;
    j:=rr;
    while (nt[j]=nt[rr])do begin
      upd(j,t[i],mm,nm);
      dec(j);
    end;
    writeln(nm);
  end;
end.
{$r-,q-,s-,i-,o+}
var
  ky,ku,tmp,cquery,cn,j,ct,n,i:longint;
  cq:array[0..400000,1..4]of longint;
  sa,x1,y1,x2,y2,x,y,xx,yy:array[0..500500]of longint;
  kol,a,nom:array[1..10]of longint;
  ans:array[0..2200000]of boolean;
  ux,uy,ut,unom:array[0..2200000]of longint;
  first:boolean;
  
  procedure qsx(l,r:longint);
    var
      i,j,tx,tmp:longint;
      
    begin
      i:=l;j:=r;
      tx:=xx[l+random(r-l+1)];
      while (i<=j)do begin
        while (tx>xx[i])do inc(i);
        while (tx<xx[j])do dec(j);
        if (i>j)then break;
        tmp:=xx[i];xx[i]:=xx[j];xx[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qsx(i,r);
      if (j>l)then qsx(l,j);
    end;
    
  procedure qsy(l,r:longint);
    var
      i,j,ty,tmp:longint;
      
    begin
      i:=l;j:=r;
      ty:=yy[l+random(r-l+1)];
      while (i<=j)do begin
        while (ty>yy[i])do inc(i);
        while (ty<yy[j])do dec(j);
        if (i>j)then break;
        tmp:=yy[i];yy[i]:=yy[j];yy[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qsy(i,r);
      if (j>l)then qsy(l,j);
    end;
    
  procedure qsu(l,r:longint);
    var
      i,j,tx,tmp:longint;
      
    begin
      i:=l;j:=r;
      tx:=ux[l+random(r-l+1)];
      while (i<=j)do begin
        while (tx>ux[i])do inc(i);
        while (tx<ux[j])do dec(j);
        if (i>j)then break;
        tmp:=ux[i];ux[i]:=ux[j];ux[j]:=tmp;
        tmp:=uy[i];uy[i]:=uy[j];uy[j]:=tmp;
        tmp:=ut[i];ut[i]:=ut[j];ut[j]:=tmp;
        tmp:=unom[i];unom[i]:=unom[j];unom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qsu(i,r);
      if (j>l)then qsu(l,j);
    end;
    
  procedure addquery(x,y,t:longint);
    begin
      inc(ku);
      ux[ku]:=x;
      uy[ku]:=y;
      ut[ku]:=t;
      unom[ku]:=cquery;
    end;
 
  procedure add(x:longint);
    begin
      while (x<=ky)do begin
        inc(sa[x]);
        x:=x or (x-1)+1;
      end;
    end;
    
  function fsum(x:longint):longint;
    var
      res:longint;
      
    begin
      res:=0;
      while (x>0)do begin
        inc(res,sa[x]);
        x:=x and (x-1);
      end;
      fsum:=res;
    end;
    
  function find(x:longint):longint;
    var
      ll,rr:longint;
      
    begin
      ll:=1;rr:=ky;
      while (ll<rr-1)do
        if (yy[(ll+rr)shr 1]>x)
          then rr:=(ll+rr)shr 1
          else ll:=(ll+rr)shr 1;
      if (yy[ll]=x)then find:=ll else find:=rr;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  randseed:=52345;
  read(n);
  for i:=1 to n do begin
    read(x[i],y[i]);
    xx[i]:=x[i];
    yy[i]:=y[i];
  end;
  qsx(1,n);
  qsy(1,n);
  for i:=1 to 9 do read(kol[i]);
  for i:=1 to 9 do nom[i]:=i;
  cn:=0;
  cquery:=0;
  first:=true;
  while (true)do begin
    inc(cn);
    if (first)then first:=false else begin
      i:=8;
      while (i>0)and(nom[i+1]<nom[i])do dec(i);
      if (i=0)then break;
      j:=i+1;
      while (j<9)and(nom[j+1]>nom[i])do inc(j);
      tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
      inc(i);
      j:=9;
      while (i<j)do begin
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;    
    end;
    for i:=1 to 9 do a[i]:=kol[nom[i]];
    ct:=a[1]+a[4]+a[7];
    if (ct<n)and(xx[ct+1]=xx[ct])then begin dec(cn);continue; end;
    x1[cn]:=2*xx[ct]+1;
    ct:=ct+a[2]+a[5]+a[8];
    if (ct<n)and(xx[ct+1]=xx[ct])then begin dec(cn);continue; end;
    x2[cn]:=2*xx[ct]+1;
    ct:=a[1]+a[2]+a[3];
    if (ct<n)and(yy[ct+1]=yy[ct])then begin dec(cn);continue; end;
    y1[cn]:=2*yy[ct]+1;
    ct:=ct+a[4]+a[5]+a[6];
    if (ct<n)and(yy[ct+1]=yy[ct])then begin dec(cn);continue; end;
    y2[cn]:=2*yy[ct]+1;
    inc(cquery);cq[cn][1]:=cquery;addquery(x1[cn],y1[cn],a[1]);
    inc(cquery);cq[cn][2]:=cquery;addquery(x2[cn],y1[cn],a[1]+a[2]);
    inc(cquery);cq[cn][3]:=cquery;addquery(x1[cn],y2[cn],a[1]+a[4]);
    inc(cquery);cq[cn][4]:=cquery;addquery(x2[cn],y2[cn],a[1]+a[2]+a[4]+a[5]);
  end;
  
  ky:=0;
  for i:=1 to n do begin
    inc(ky);yy[ky]:=2*y[i];
    inc(ky);yy[ky]:=2*y[i]+1;
  end;
  qsy(1,ky);
  j:=1;
  for i:=2 to ky do
    if (yy[i]<>yy[j])then begin
      inc(j);yy[j]:=yy[i];
    end;
  ky:=j;
  for i:=1 to n do begin
    inc(ku);
    ux[ku]:=2*x[i];
    uy[ku]:=2*y[i];
    ut[ku]:=-1;
    unom[ku]:=-1;
  end;
  qsu(1,ku);
  
  for i:=1 to ku do 
    if (ut[i]<0)
      then add(find(uy[i])) 
      else ans[unom[i]]:=fsum(find(uy[i]))=ut[i];
  
  for i:=1 to cn do 
    if (ans[cq[i][1]])and(ans[cq[i][2]])and
       (ans[cq[i][3]])and(ans[cq[i][4]])then begin
         writeln(x1[i]/2:0:5,' ',x2[i]/2:0:5);
         writeln(y1[i]/2:0:5,' ',y2[i]/2:0:5);
         halt(0);
       end;
  writeln(-1);
end.
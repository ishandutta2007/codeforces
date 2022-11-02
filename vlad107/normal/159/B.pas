{$r-,q-,s-,i-,o+}
var
  t,p,n,m,i,res,j:longint;
  a,b,x,y:array[0..500500]of longint;
  
  procedure qs(l,r:longint);
    var
      i,j,nn,xx,yy,tmp:longint;
    
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=x[nn];
      yy:=y[nn];
      while (i<=j)do begin
        while (xx>x[i])or(xx=x[i])and(yy>y[i])do inc(i);
        while (xx<x[j])or(xx=x[j])and(yy<y[j])do dec(j);
        if (i>j)then break;
        tmp:=x[i];x[i]:=x[j];x[j]:=tmp;
        tmp:=y[i];y[i]:=y[j];y[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(I,r);
      if (j>l)then qs(l,j);
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,m);
  for i:=1 to n do read(y[i],x[i]);
  qs(1,n);
  for i:=1 to n do a[i]:=x[i];
  for i:=1 to n do b[i]:=y[i];
  for i:=1 to m do read(y[i],x[i]);
  qs(1,m);
  
  j:=1;
  res:=0;
  for i:=1 to m do begin
    if (x[i]=x[i-1])then continue;
    p:=i;
    while (p<=m)and(x[p]=x[i])do inc(p);
    dec(p);
    
    while (j<=n)and(a[j]<x[i])do inc(j);
    if (a[j]<>x[i])then continue;
    t:=j;
    while (t<=n)and(a[t]=x[i])do inc(t);
    dec(t);
    if (t-j+1<p-i+1)then inc(res,t-j+1)else inc(res,p-i+1);
  end;
  write(res,' ');
  res:=0;
  j:=1;
  for i:=1 to m do begin
    while (j<=n)and((a[j]<x[i])or((a[j]=x[i])and(b[j]<y[i])))do inc(j);
    if (a[j]=x[i])and(b[j]=y[i])then begin
      inc(res);
      inc(j);
    end;
  end;
  writeln(res);
  close(output);close(input);
end.
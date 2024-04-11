{$r-,q-,s-,i-,o+}
var
  cr,res:extended;
  i,n:longint;
  w,p:array[0..500500]of longint;
  
  procedure qs(l,r:longint);
    var
      nn,xx,yy,tmp,i,j:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=w[nn];
      yy:=p[nn];
      while (i<=j)do begin
        while (xx*p[i]<w[i]*yy)do inc(i);
        while (xx*p[j]>w[j]*yy)do dec(j);
        if (i>j)then break;
        tmp:=w[i];w[i]:=w[j];w[j]:=tmp;
        tmp:=p[i];p[i]:=p[j];p[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  read(n);
  res:=0;
  for i:=1 to n do begin
    read(w[i],p[i]);
    res:=res+w[i];
    w[i]:=w[i]*p[i];
    p[i]:=100-p[i];
  end;
  qs(1,n);
  cr:=0;
  for i:=1 to n do begin
    res:=res+cr*p[i]/100;
    cr:=cr+w[i]/100;
  end;
  writeln(res:0:10);
end.
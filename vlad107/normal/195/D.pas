{$r-,q-,s-i-,o+}
const
  eps=1e-8;
  inf=1e9;

var
  kt,res,n,i:longint;
  k,b:array[0..500500]of longint;
  tx,ty:array[0..500500]of int64;
  
  procedure qs2(l,r:longint);
    var
      nn,i,j:longint;
      xx,yy,tmp:int64;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=tx[nn];
      yy:=ty[nn];
      while (i<=j)do begin
        while (xx*ty[i]>tx[i]*yy)do inc(i);
        while (xx*ty[j]<tx[j]*yy)do dec(j);
        if (i>j)then break;
        tmp:=tx[i];tx[i]:=tx[j];tx[j]:=tmp;
        tmp:=ty[i];ty[i]:=ty[j];ty[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs2(i,r);
      if (j>l)then qs2(l,j);
    end;

begin
  randomize;
  read(n);
  for i:=1 to n do read(k[i],b[i]);
  kt:=0;
  for i:=1 to n do begin
    if (k[i]=0)then continue;
    inc(kt);
    tx[kt]:=-b[i];
    ty[kt]:=k[i];
    if (ty[kt]<0)then begin
      tx[kt]:=-tx[kt];
      ty[kt]:=-ty[kt];
    end;
  end;
  qs2(1,kt);
  res:=ord(kt>0);
  for i:=2 to kt do begin
    if (tx[i]*ty[i-1]=tx[i-1]*ty[i])then continue;
    inc(res);
  end;
  writeln(res);
end.
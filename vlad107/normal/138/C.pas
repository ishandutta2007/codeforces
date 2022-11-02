{$r-,q-,s-,i-,o+}
const
  eps=1e-5;

var     
  all,kt,x,hx,n,m,i,j:longint;
  pl,pr,pp,res:extended;
  p:array[0..1000500]of extended;
  t,tq:array[0..1000500]of longint;

  procedure qs(l,r:longint);
    var
      tmp:extended;
      nn,xx,yy,i,j,t2:longint;

    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=t[nn];
      yy:=tq[nn];
      while (i<=j)do begin
        while (xx>t[i])or(xx=t[i])and(yy>tq[i])do inc(i);
        while (xx<t[j])or(xx=t[j])and(yy<tq[j])do dec(j);
        if (i>j)then break;
        tmp:=p[i];p[i]:=p[j];p[j]:=tmp;
        t2:=t[i];t[i]:=t[j];t[j]:=t2;
        t2:=tq[i];tq[i]:=tq[j];tq[j]:=t2;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  randomize;
  read(n,m);
  kt:=0;
  for i:=1 to n do begin
    read(x,hx,pl,pr);
    pl:=pl/100;
    pr:=pr/100;

    inc(kt);
    t[kt]:=x-hx;
    if (abs(pl-1)<eps)then p[kt]:=-1 else p[kt]:=1-pl;
    tq[kt]:=0;

    inc(kt);
    t[kt]:=x;
    if (abs(pl-1)<eps)then p[kt]:=-2 else p[kt]:=1/(1-pl);
    tq[kt]:=0;

    inc(kt);
    t[kt]:=x+1;
    if (abs(pr-1)<eps)then p[kt]:=-1 else p[kt]:=1-pr;
    tq[kt]:=0;

    inc(kt);
    t[kt]:=x+hx+1;
    if (abs(pr-1)<eps)then p[kt]:=-2 else p[kt]:=1/(1-pr);
    tq[kt]:=0;
  end;

  for i:=1 to m do begin
    read(x,hx);
    inc(kt);
    t[kt]:=x;
    p[kt]:=hx;
    tq[kt]:=1;
  end;
  qs(1,kt);

  pp:=ln(1);
  all:=0;
  res:=0;
  for i:=1 to kt do
    if (tq[i]=0)then begin
      if (abs(p[i]+1)<eps)then inc(all)else
      if (abs(p[i]+2)<eps)then dec(all)else
      pp:=pp+ln(p[i]);
    end else res:=res+exp(pp)*p[i]*ord(all=0);
  writeln(res:0:10);
end.
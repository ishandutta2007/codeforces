{$R-,S-,Q-,I-,O+}
{$M 10000000}
var
  x,qm,qp,qx,qy: array [0..250010] of longint;
  qd,qr: array [0..250010] of int64;
  was: array [0..250010] of boolean;
  a,pnt: array [0..21,0..250010] of longint;
  xs,ys,n,i,e,ll,rr,mid: longint;
  rad: int64;

procedure Sort(l,r:longint);
var
  i,j,pp,x,tmp: longint;
  xx,tt: int64;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x:=qm[pp]; xx:=qd[pp];
  repeat
    while (qm[i] < x) or (qm[i] = x) and (qd[i] < xx) do inc(i);
    while (x < qm[j]) or (x = qm[j]) and (xx < qd[j]) do dec(j);
    if i <= j then
    begin
      tmp:=qm[i]; qm[i]:=qm[j]; qm[j]:=tmp;
      tmp:=qp[i]; qp[i]:=qp[j]; qp[j]:=tmp;
      tt:=qd[i]; qd[i]:=qd[j]; qd[j]:=tt;
      tt:=qr[i]; qr[i]:=qr[j]; qr[j]:=tt;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure build(x,l,r:longint);
var
  i,j,k,mid: longint;
begin
  pnt[x,l]:=l;
  if l = r then a[x,l]:=l else
  begin
    mid:=(l+r) shr 1;
    build(x+1,l,mid);
    build(x+1,mid+1,r);
    i:=l; j:=mid+1; k:=l;
    while (i <= mid) or (j <= r) do
      if (i <= mid) and (qd[a[x+1,i]] < qd[a[x+1,j]]) or (j > r) then
      begin
        a[x,k]:=a[x+1,i];
        inc(i); inc(k);
      end else
      begin
        a[x,k]:=a[x+1,j];
        inc(j); inc(k);
      end;
  end;
end;

procedure go(xx,l,r,rr:longint);
var
  j: longint;
begin
  if l > rr then exit;
  if r <= rr then
  begin
    j:=pnt[xx,l];
    while (j <= r) and (qd[a[xx,j]] <= rad) do
    begin
      if not was[a[xx,j]] then
      begin
        inc(e);
        x[e]:=a[xx,j];
        was[x[e]]:=True;
      end;
      inc(j);
    end;
    pnt[xx,l]:=j;
  end else
  begin
    mid:=(l+r) shr 1;
    go(xx+1,l,mid,rr);
    go(xx+1,mid+1,r,rr);
  end;
end;

begin
  randomize;
  read(xs,ys,qp[0],qr[0],n);
  qr[0]:=qr[0]*qr[0];
  for i:=1 to n do
  begin
    read(qx[i],qy[i],qm[i],qp[i],qr[i]);
    qr[i]:=qr[i]*qr[i];
    qd[i]:=int64(xs-qx[i])*(xs-qx[i])+int64(ys-qy[i])*(ys-qy[i]);
  end;
  Sort(1,n);
  build(1,1,n);
  fillchar(was,sizeof(was),False);
  was[0]:=True;
  i:=1; e:=1;
  x[1]:=0;
  while i <= e do
  begin
    ll:=0; rr:=n;
    while ll < rr do
    begin
      mid:=(ll+rr+1) shr 1;
      if qm[mid] <= qp[x[i]] then ll:=mid
      else rr:=mid-1;
    end;
    rad:=qr[x[i]];
    if ll > 0 then go(1,1,n,ll);
    inc(i);
  end;
  writeln(e-1);
end.
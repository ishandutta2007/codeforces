{$r-,q-,s-,i-,o+}
const
  inf=1000000001;
var
  ll,rr,n,i,qb,qe:longint;
  a,q:array[0..2000500]of longint;
  sum,m:int64;
  function ok(x:longint):boolean;
    var
      i:longint;
      cr:int64;
    begin
      cr:=0;
      for i:=1 to n do 
        if (x>a[i])
          then cr:=cr+a[i]
          else cr:=cr+x;
      ok:=cr<=m;
    end;
begin
  read(n,m);
  for i:=1 to n do begin
    read(a[i]);
    sum:=sum+a[i];
  end;
  if (sum<m)then begin
    writeln(-1);
    exit;
  end;
  ll:=0;rr:=inf;
  while (ll<rr-1)do 
    if (ok((ll+rr)shr 1))
      then ll:=(ll+rr)shr 1
      else rr:=(ll+rr)shr 1;
  if (ok(rr))then ll:=rr;
  for i:=1 to n do 
    if (ll>=a[i])
      then begin
        m:=m-a[i];
        a[i]:=0;
      end else begin
        dec(a[i],ll);
        m:=m-ll;
      end;
  qb:=0;qe:=0;
  for i:=1 to n do 
    if (a[i]<>0)then begin
      inc(qe);
      q[qe]:=i;
    end;
  while (m>0)do begin
    m:=m-1;
    inc(qb);
    dec(a[q[qb]]);
    if (a[q[qb]]<>0)then begin
      inc(qe);
      q[qe]:=q[qb];
    end;
  end;
  for i:=qb+1 to qe do write(q[i],' ');
end.
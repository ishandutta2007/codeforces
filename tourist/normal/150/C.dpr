{$R-,S-,Q-,I-,O+}
{$M 10000000}
type node = record
              left,right,sum,inner: double;
            end;
var
  t: array [0..1000010] of node;
  a: array [0..1000010] of double;
  p,x,len: array [0..1000010] of longint;
  ll,rr,n,m,c,i: longint;
  ans: double;

procedure union(var a,b:node);
var
  na,nb,nd: double;
begin
  na:=a.left; nb:=b.right; nd:=a.inner;
  if a.sum+b.left < na then na:=a.sum+b.left;
  if a.right+b.sum < nb then nb:=a.right+b.sum;
  if b.inner < nd then nd:=b.inner;
  if a.right+b.left < nd then nd:=a.right+b.left;
  a.left:=na;
  a.right:=nb;
  a.sum:=a.sum+b.sum;
  a.inner:=nd;
end;

procedure build(x,l,r:longint);
begin
  if l = r then
  begin
    t[x].left:=a[l];
    t[x].right:=a[l];
    t[x].sum:=a[l];
    t[x].inner:=a[l];
  end else
  begin
    build(x+x,l,(l+r) shr 1);
    build(x+x+1,(l+r) shr 1+1,r);
    t[x]:=t[x+x];
    union(t[x],t[x+x+1]);
  end;
end;

procedure go(x,l,r,ll,rr:longint);
begin
  if (l >= ll) and (r <= rr) then union(t[0],t[x]) else
  begin
    if ll <= (l+r) shr 1 then go(x+x,l,(l+r) shr 1,ll,rr);
    if rr > (l+r) shr 1 then go(x+x+1,(l+r) shr 1+1,r,ll,rr);
  end;
end;

begin
  read(n,m,c);
  for i:=1 to n do read(x[i]);
  dec(n);
  for i:=1 to n do len[i]:=x[i+1]-x[i];
  for i:=1 to n do read(p[i]);
  for i:=1 to n do a[i]:=p[i]*c*0.01-len[i]*0.5;
  build(1,1,n);
  ans:=0;
  for i:=1 to m do
  begin
    read(ll,rr);
    t[0].left:=0;
    t[0].right:=0;
    t[0].sum:=0;
    t[0].inner:=0;
    go(1,1,n,ll,rr-1);
    ans:=ans-t[0].inner;
  end;
  writeln(ans:0:17);
end.
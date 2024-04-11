uses
  math;

const
  inf=1000000000;

var
  t,mid,n,m,x,y,k,i,dx,dy:longint;
  ans:int64;

  function find(x,dx,n:longint):longint;
    var
      nx:int64;
      mid,ll,rr:longint;
      
    begin
      if (dx=0)then begin
        find:=inf;
        exit;
      end;
      ll:=0;rr:=inf;
      while (ll<rr-1)do begin
        mid:=(ll+rr)shr 1;
        nx:=int64(mid)*dx+x;
        if (nx>n)or(nx<1)then rr:=mid else ll:=mid;
      end;
      if (int64(dx)*rr+x<=n)and(int64(dx)*rr+x>0)then find:=rr else find:=ll;
    end;

begin
  read(n,m,x,y,k);
  ans:=0;
  for i:=1 to k do begin
    read(dx,dy);
    t:=min(find(x,dx,n),find(y,dy,m));
    ans:=ans+t;
    x:=x+dx*t;
    y:=y+dy*t;
  end;
  writeln(ans);
end.
{$M 10000000}
const
  INF=trunc(1e9);
var
  iter,n,kx,ky,i:longint;
  cr,h,ra:array[0..70] of longint;
  procedure modh(x,q:longint);
    begin
      inc(h[x],kx*q);
      inc(h[x-1],ky*q);
      inc(h[x+1],ky*q);
    end;
  procedure rec(x:longint);
    var
      kq:longint;
    begin
      if (cr[0]>ra[0])then exit;
      if (cr[0]>52)then exit;
      if (h[x-1]>=0)then begin
        inc(cr[0]);
        cr[cr[0]]:=x;
        modh(x,-1);
        rec(x);
        dec(cr[0]);
        modh(x,1);
        exit;
      end;
      if (x=n-1)then begin
        kq:=0;
        while (h[x]>=0)or(h[x+1]>=0) do begin
          modh(x,-1);
          inc(cr[0]);
          cr[cr[0]]:=x;
          inc(kq);
        end;
        if (cr[0]<ra[0])then ra:=cr;
        dec(cr[0],kq);
        modh(x,kq);
        exit;
      end;
      if (h[x]>=0)or(h[x+1]>=0)then begin
        inc(cr[0]);
        cr[cr[0]]:=x;
        modh(x,-1);
        rec(x);
        modh(x,1);
        dec(cr[0]);
      end;
      rec(x+1);
    end;
begin
  iter:=0;
  read(n,kx,ky);
  for i:=1 to n do read(h[i]);
  ra[0]:=INF;
  cr[0]:=0;rec(2);
  writeln(ra[0]);
  for i:=1 to ra[0]do write(ra[i],' ');
end.
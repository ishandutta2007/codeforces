{$r-,q-,s-,i-,o+}
var
  l,r,n,i,tt,px,py:longint;
  res:int64;
  x,y:array[1..250000]of int64;
begin
  read(n);
  for i:=1 to n do begin
    read(x[i],y[i]);
    x[i+n]:=x[i];
    y[i+n]:=y[i];
  end;
  read(tt);
  while (tt>0)do begin
    res:=int64(n)*(n-1)*(n-2)div 6;
    dec(tt);
    read(px,py);
    r:=1;
    for i:=1 to n-1 do
      if (y[i+1]-y[i])*(px-x[i])<(x[i+1]-x[i])*(py-y[i])then begin
        r:=-1;
        break;
      end;
    if (r<0)then begin
      writeln(0);
      continue;
    end;
    for l:=1 to n do begin
      while (r<l+n-1)do begin
        if (y[r+1]-y[l])*(px-x[l])<(x[r+1]-x[l])*(py-y[l])
          then break;
        inc(r);
      end;
      dec(res,int64(r-l)*(r-l-1) div 2);
    end;
    writeln(res);
  end;
end.
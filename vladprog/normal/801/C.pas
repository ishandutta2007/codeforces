{type
  extended=real;}

var
  a,b:array[1..200000]of int64;
  c,d:array[1..200000]of extended;
  n,p,sa,sb:int64;
  i:longint;
  l,r,m,s:extended;

begin
  read(n,p);
  sa:=0;
  sb:=0;
  for i:=1 to n do
    begin
      read(a[i],b[i]);
      c[i]:=b[i]/a[i];
      d[i]:=p/a[i];
      inc(sa,a[i]);
      inc(sb,b[i])
    end;
  if p>=sa
    then writeln(-1)
    else
      begin
        l:=0;
        r:=sb/(sa-p);
        while (r-l)>0.000001 do
          begin
            m:=(l+r)/2;
            s:=m;
            for i:=1 to n do
              if m>c[i] then
                s:=s-(m-c[i])/d[i];
            if s>0
              then l:=m
              else r:=m
          end;
        writeln(l)
      end
end.
var
  n,h,i:longint;
  l,r,m,s:extended;

begin
  read(n,h);
  s:=h/2;
  m:=0;
  for i:=1 to n-1 do
    begin
      l:=m;
      r:=h;
      while r-l>1e-7 do
        begin
          m:=(l+r)/2;
          if sqr(m)/2/h>i*s/n
            then r:=m
            else l:=m
        end;
      m:=(l+r)/2;
      write(m:0:7,' ')
    end
end.
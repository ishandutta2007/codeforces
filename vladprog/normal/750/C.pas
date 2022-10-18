uses
  math;

var
  n,c,d,i,l,r:longint;
  inf:boolean;

begin
  read(n);
  l:=-1000000000;
  r:= 1000000000;
  inf:=true;
  for i:=1 to n do
    begin
      read(c,d);
      if d=2
        then inf:=false;
      if d=1
        then l:=max(l,1900)
        else r:=min(r,1899);
      inc(l,c);
      inc(r,c)
    end;
  if l>r
    then writeln('Impossible')
    else if inf
      then writeln('Infinity')
      else writeln(r)
end.
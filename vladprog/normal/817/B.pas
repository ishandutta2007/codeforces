const
  inf=2000000000;

procedure swap(var a,b:int64);
var
  t:int64;
begin
  t:=a;
  a:=b;
  b:=t
end;

function c2(n:int64):int64;
begin
  c2:=n*(n-1) div 2
end;

function c3(n:int64):int64;
begin
  c3:=n*(n-1)*(n-2) div 6
end;

var
  i:longint;
  n,m1,m2,m3,a,k1,k2,k3:int64;
  c:boolean;

begin
  read(n);
  m1:=inf;
  m2:=inf;
  m3:=inf;
  k1:=0;
  k2:=0;
  k3:=0;
  for i:=1 to n do
    begin
      read(a);
      c:=false;
      if a=m3 then begin inc(k3); c:=true end;
      if a=m2 then begin inc(k2); c:=true end;
      if a=m1 then begin inc(k1); c:=true end;
      if c then continue;
      
      if a<m1 then
        begin
          m3:=m2;
          m2:=m1;
          m1:=a;
          k3:=k2;
          k2:=k1;
          k1:=1;
          continue
        end;
      
      if a<m2 then
        begin
          m3:=m2;
          m2:=a;
          k3:=k2;
          k2:=1;
          continue
        end;
      
      if a<m3 then
        begin
          m3:=a;
          k3:=1;
          continue
        end;
      
      {if a <m3 then begin swap( a,m3); k3:=1 end;
      if m3<m2 then begin swap(m3,m2); swap(k3,k2) end;
      if m2<m1 then begin swap(m2,m1); swap(k2,k1) end}
    end;
  if k1>1 then
    begin
      m3:=m2;
      m2:=m1;
      k3:=k2;
      k2:=k1-1;
      k1:=1
    end;
  if k2>1 then
    begin
      m3:=m2;
      k3:=k2-1;
      k2:=1
    end;
  //writeln(m1,' ',m2,' ',m3,' | ',k1,' ',k2,' ',k3);
  if (m1=m2)and(m2=m3)
      then writeln(c3(k1+k2+k3))
      else if m1=m2
        then writeln(c2(k1+k2)*k3)
        else if m2=m3
          then writeln(k1*c2(k2+k3))
          else writeln(k1*k2*k3)
end.
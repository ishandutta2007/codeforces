{$R-,S-,Q-,I-,O+}
var
  s,n1,n2,n3,r1,r2,r3,d1,d2,i,j,ii,t,k,n,sd: longint;
  ans,lg,rg,nr1,nr2,nr3: double;
  x,z: array [0..22] of longint;
  c,dmg: array [0..22,0..3] of double;
  f: array [0..22,0..22] of double;
begin
  read(n1,n2,n3,r1,r2,r3,d1,d2);
  nr1:=sqrt(r1*r1-1);
  nr2:=sqrt(r2*r2-1);
  nr3:=sqrt(r3*r3-1);
  for i:=0 to 20 do
    for j:=1 to 2 do
    begin
      if j = 1 then
      begin
        lg:=-nr1; rg:=nr1;
      end else
      begin
        lg:=-nr2; rg:=nr2;
      end;
      if i-nr3 > lg then lg:=i-nr3;
      if i+nr3 < rg then rg:=i+nr3;
      if lg > rg then dmg[i,j]:=0 else
      if j = 1 then dmg[i,j]:=(rg-lg)*d1
      else dmg[i,j]:=(rg-lg)*d2;
    end;
  n:=n1+n2+n3;
  ans:=0;
  for sd:=1 to 2 do
  begin
    j:=sd;
    for i:=1 to n do
    begin
      x[i]:=(j+1) div 2;
      inc(j);
    end;
    for t:=0 to 1 shl n-1 do
    begin
      for i:=1 to n do
        if t and (1 shl (i-1)) > 0 then z[i]:=3
        else z[i]:=0;
      s:=0;
      for i:=1 to n do s:=s+z[i];
      if s <> 3*n3 then continue;
      ii:=0;
      for i:=1 to n do
        if z[i] = 0 then
        begin
          inc(ii);
          for j:=1 to 2 do
          begin
            c[ii,j]:=0;
            for k:=1 to n do
              if z[k] = 3 then c[ii,j]:=c[ii,j]+dmg[abs(x[i]-x[k]),j];
          end;
        end;
      for i:=0 to n1 do
        for j:=0 to n2 do
          if i+j = 0 then f[i,j]:=0 else
          begin
            f[i,j]:=0;
            if i > 0 then f[i,j]:=f[i-1,j]+c[i+j,1];
            if j > 0 then
              if f[i,j-1]+c[i+j,2] > f[i,j] then f[i,j]:=f[i,j-1]+c[i+j,2];
          end;
      if f[n1,n2] > ans then ans:=f[n1,n2];
    end;
  end;
  ans:=ans+n1*2*nr1*d1+n2*2*nr2*d2;
  writeln(ans:0:17);
end.
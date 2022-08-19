{$R-,S-,Q-,I-,O+}
var
  lg,rg,zz,ha,ta,la,ra,pa,hb,tb,lb,rb,pb,q,time,h1,h2,z: longint;
  v: array [0..66] of longint;
  a,b,c: array [0..66] of double;
  tot,w: double;
  sa,sb,f: array [-1..210,-1..210,-1..66] of double;
begin
  read(ha,ta,la,ra,pa);
  read(hb,tb,lb,rb,pb);
  q:=0;
  for time:=0 to ta*tb-1 do
  begin
    if time mod ta = 0 then
    begin
      inc(q);
      v[q]:=1;
    end;
    if time mod tb = 0 then
    begin
      inc(q);
      v[q]:=2;
    end;
  end;
  fillchar(f,sizeof(f),0);
  fillchar(sa,sizeof(sa),0);
  fillchar(sb,sizeof(sb),0);
  for h1:=0 to ha do
    for h2:=0 to hb do
    begin
      for z:=1 to q do
      begin
        if z = q then zz:=1
        else zz:=z+1;
        b[z]:=0;
        if h2 = 0 then a[z]:=1 else
        if h1 = 0 then a[z]:=0 else
        if v[z] = 1 then
        begin
          b[z]:=0.01*pa;
          lg:=h2-ra; rg:=h2-la;
          if rg < 0 then tot:=ra-la+1 else
          if lg < 0 then tot:=sb[h1,rg,zz]+(-lg)
          else tot:=sb[h1,rg,zz]-sb[h1,lg-1,zz];
          a[z]:=(1-b[z])*tot/(ra-la+1);
        end else
        begin
          b[z]:=0.01*pb;
          lg:=h1-rb; rg:=h1-lb;
          if rg < 0 then tot:=0 else
          if lg < 0 then tot:=sa[rg,h2,zz]
          else tot:=sa[rg,h2,zz]-sa[lg-1,h2,zz];
          a[z]:=(1-b[z])*tot/(rb-lb+1);
        end;
      end;
      c[1]:=a[1]; w:=b[1];
      for z:=2 to q do
      begin
        c[1]:=c[1]+a[z]*w;
        w:=w*b[z];
      end;
      for z:=q downto 2 do
      begin
        if z = q then zz:=1
        else zz:=z+1;
        c[z]:=b[z]*c[zz]+(1-w)*a[z];
      end;
      for z:=1 to q do
        if w > 1-1e-10 then f[h1,h2,z]:=c[z]
        else f[h1,h2,z]:=c[z]/(1-w);
      for z:=1 to q do sa[h1,h2,z]:=f[h1,h2,z]+sa[h1-1,h2,z];
      for z:=1 to q do sb[h1,h2,z]:=f[h1,h2,z]+sb[h1,h2-1,z];
    end;
  writeln(f[ha,hb,1]:0:17);
end.
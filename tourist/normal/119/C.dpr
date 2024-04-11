{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const inf = round(1e18);
var
  ki,kk,n,m,u,i,j,k,ni,z,q: longint;
  max,ft,tmp,x,y: int64;
  cnt,a,b: array [0..101] of int64;
  ans,c,d: array [0..101] of longint;
  ok: array [0..51,0..101,0..51,0..101] of boolean;
  f: array [0..51,0..51,0..101] of int64;
  fz,fq: array [0..51,0..51,0..101] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,u);
  for i:=1 to m do read(a[i],b[i],c[i]);
  for i:=1 to m do d[i]:=i;
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if c[i] > c[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
        tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
        tmp:=c[i]; c[i]:=c[j]; c[j]:=tmp;
        tmp:=d[i]; d[i]:=d[j]; d[j]:=tmp;
      end;
  for i:=1 to m do
    for j:=1 to n do
      for k:=0 to b[i]-a[i] do f[i,j,k]:=-inf;
  for i:=1 to m do
    for k:=0 to b[i]-a[i] do f[i,1,k]:=a[i]+k;
  fillchar(ok,sizeof(ok),False);
  for i:=1 to m do
    for k:=0 to b[i]-a[i] do
      for j:=i+1 to m do
        for q:=0 to b[j]-a[j] do
        begin
          x:=a[i]+k;
          y:=a[j]+q;
          if (y = x+u) or (y = x*u) then ok[j,q,i,k]:=True;
        end;
  for i:=2 to m do
    for j:=2 to n do
      if j > i then continue else
      for k:=0 to b[i]-a[i] do
        for z:=1 to i-1 do
          if c[i] > c[z] then
            for q:=0 to b[z]-a[z] do
              if ok[i,k,z,q] and (f[z,j-1,q] >= 0) then
              begin
                ft:=f[z,j-1,q]+a[i]+k;
                if ft > f[i,j,k] then
                begin
                  f[i,j,k]:=ft;
                  fz[i,j,k]:=z;
                  fq[i,j,k]:=q;
                end;
              end;
  max:=-1;
  ki:=0; kk:=0;
  for i:=1 to m do
    for k:=0 to b[i]-a[i] do
      if f[i,n,k] > max then
      begin
        max:=f[i,n,k];
        ki:=i;
        kk:=k;
      end;
  if max < 0 then writeln('NO') else
  begin
    writeln('YES');
    i:=ki; k:=kk;
    for j:=n downto 1 do
    begin
      ans[j]:=d[i];
      cnt[j]:=a[i]+k;
      if j = 1 then break;
      ni:=fz[i,j,k];
      k:=fq[i,j,k];
      i:=ni;
    end;
    for j:=1 to n do writeln(ans[j],' ',cnt[j]);
  end;
  close(input);
  close(output);
end.
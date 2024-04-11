{$R-,S-,Q-,I-,O+}
const co = 200;
var
  z,u,it,n,i,j,m: longint;
  mid,ll,rr: extended;
  d,p: array [0..210] of extended;
  ss,ff: array [0..40010] of longint;
  dd: array [0..40010] of extended;
begin
  read(n);
  for i:=0 to n do read(p[i]);
  m:=0;
  for i:=0 to co do
    for j:=0 to n do
      if j <= i then
      begin
        inc(m);
        ss[m]:=i;
        ff[m]:=i+n-2*j;
        if ff[m] > co then ff[m]:=co;
        dd[m]:=1-p[j];
      end;
  ll:=0; rr:=1;
  for it:=1 to 25 do
  begin
    mid:=(ll+rr)*0.5;
    for i:=0 to co do d[i]:=0;
    u:=0;
    for z:=0 to co+1 do
      for i:=1 to m do
        if d[ss[i]]+dd[i]-mid < d[ff[i]] then
        begin
          d[ff[i]]:=d[ss[i]]+dd[i]-mid;
          u:=z;
        end;
    if u = co+1 then rr:=mid
    else ll:=mid;
  end;
  writeln(1-(ll+rr)*0.5:0:10);
end.
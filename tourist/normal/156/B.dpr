{$R-,S-,Q-,I-,O+}
var
  n,m,i,s,kt,p,r: longint;
  cnt,a: array [-100010..100010] of longint;
  w: array [0..100010] of boolean;
begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  fillchar(cnt,sizeof(cnt),0);
  for i:=1 to n do inc(cnt[a[i]]);
  s:=0;
  for i:=-n to -1 do s:=s+cnt[i];
  kt:=0;
  for p:=1 to n do
  begin
    r:=s-cnt[-p]+cnt[p];
    w[p]:=r = m;
    if r = m then inc(kt);
  end;
  for i:=1 to n do
    if a[i] > 0 then
    begin
      if not w[a[i]] then writeln('Lie') else
      if kt = 1 then writeln('Truth')
      else writeln('Not defined');
    end else
    begin
      if not w[-a[i]] then writeln('Truth') else
      if kt = 1 then writeln('Lie')
      else writeln('Not defined');
    end;
end.
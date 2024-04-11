{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,t,i,j,tmp,ans,v: longint;
  x,a: array [0..10010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,t);
  for i:=1 to n do read(x[i],a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if x[i] > x[j] then
      begin
        tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      end;
  ans:=2;
  for i:=1 to n-1 do
  begin
    v:=2*(x[i+1]-x[i])-(a[i]+a[i+1]);
    if v > 2*t then inc(ans);
    if v >= 2*t then inc(ans);
  end;
  writeln(ans);
  close(input);
  close(output);
end.
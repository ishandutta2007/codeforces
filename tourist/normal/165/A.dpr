{$R-,S-,Q-,I-,O+}
var
  n,i,ans,j,cnt: longint;
  x,y: array [0..210] of longint;
begin
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  ans:=0;
  for i:=1 to n do
  begin
    cnt:=0;
    for j:=1 to n do
      if (x[j] > x[i]) and (y[j] = y[i]) then begin inc(cnt); break; end;
    for j:=1 to n do
      if (x[j] < x[i]) and (y[j] = y[i]) then begin inc(cnt); break; end;
    for j:=1 to n do
      if (x[j] = x[i]) and (y[j] < y[i]) then begin inc(cnt); break; end;
    for j:=1 to n do
      if (x[j] = x[i]) and (y[j] > y[i]) then begin inc(cnt); break; end;
    if cnt = 4 then inc(ans);
  end;
  writeln(ans);
end.
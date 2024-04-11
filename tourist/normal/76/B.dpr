{$R-,S-,Q-,I-,O+}
var
  n,m,y0,y1,i,j,ans,dist: longint;
  ok: boolean;
  a,b,min: array [0..100010] of longint;
begin
  read(n,m,y0,y1);
  for i:=1 to n do read(b[i]);
  for i:=1 to m do read(a[i]);
  for i:=1 to m do min[i]:=round(1e9);
  j:=0; ans:=n;
  for i:=1 to n do
  begin
    while (j < m) and (a[j+1] <= b[i]) do inc(j);
    dist:=maxlongint;
    if j > 0 then dist:=abs(a[j]-b[i]);
    ok:=False;
    if j+1 <= m then
      if abs(a[j+1]-b[i]) <= dist then
      begin
        dist:=abs(a[j+1]-b[i]);
        ok:=True;
      end;
    if j > 0 then
      if abs(a[j]-b[i]) = dist then
        if (min[j] = round(1e9)) or (min[j] = dist) or not ok then
        begin
          if dist < min[j] then
          begin
            if min[j] < round(1e9) then inc(ans);
            min[j]:=dist;
          end;
          if dist = min[j] then dec(ans);
          continue;
        end;
    if dist < min[j+1] then
    begin
      if min[j+1] < round(1e9) then inc(ans);
      min[j+1]:=dist;
    end;
    if dist = min[j+1] then dec(ans);
  end;
  writeln(ans);
end.
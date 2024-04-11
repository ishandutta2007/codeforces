{$R-,S-,Q-,I-,O+}
var
  l1,r1,l2,r2: longint;

function go(l1,r1,l2,r2:longint):longint;
var
  ans,cur,lg,rg,m1,m2,i: longint;
begin
  if (l1 > r1) or (l2 > r2) then
  begin
    go:=0;
    exit;
  end;
  for i:=29 downto 0 do
    if (l1 > 1 shl i) and (r1 < 1 shl (i+1)) then
    begin
      dec(l1,1 shl i);
      dec(r1,1 shl i);
    end;
  for i:=29 downto 0 do
    if (l2 > 1 shl i) and (r2 < 1 shl (i+1)) then
    begin
      dec(l2,1 shl i);
      dec(r2,1 shl i);
    end;
  if (l1 <= l2) and (r2 <= r1) then
  begin
    go:=r2-l2+1;
    exit;
  end;
  if (l2 <= l1) and (r1 <= r2) then
  begin
    go:=r1-l1+1;
    exit;
  end;
  m1:=1;
  while m1 shl 1 <= r1 do m1:=m1 shl 1;
  m2:=1;
  while m2 shl 1 <= r2 do m2:=m2 shl 1;
  if m1 = m2 then
  begin
    lg:=l1; rg:=r1;
    if l2 > lg then lg:=l2;
    if r2 < rg then rg:=r2;
    ans:=rg-lg+1;
    if (l1 < l2) and (r1 < r2) then
    begin
      cur:=go(l1,m1-1,m1+1,r2);
      if cur > ans then ans:=cur;
    end else
    if (l2 < l1) and (r2 < r1) then
    begin
      cur:=go(l2,m1-1,m1+1,r1);
      if cur > ans then ans:=cur;
    end;
    go:=ans;
  end else
  if m1 > m2 then
  begin
    ans:=go(l1,m1-1,l2,r2);
    cur:=go(m1+1,r1,l2,r2);
    if cur > ans then ans:=cur;
    go:=ans;
  end else
  begin
    ans:=go(l1,r1,l2,m2-1);
    cur:=go(l1,r1,m2+1,r2);
    if cur > ans then ans:=cur;
    go:=ans;
  end;
end;

begin
  read(l1,r1,l2,r2);
  writeln(go(l1,r1,l2,r2));
end.
{$R-,S-,Q-,I-,O+}
var
  a,ans: array [0..1111111] of char;
  n,r,z,i,min,mlen: longint;

procedure go(x,y:longint);
var
  len,cur,i: longint;
begin
  len:=0;
  while x <> y do
    if x > y then
    begin
      inc(len);
      a[len]:='T';
      x:=x-y;
    end else
    begin
      inc(len);
      a[len]:='B';
      y:=y-x;
    end;
  if x > 1 then exit;
  inc(len);
  a[len]:='T';
  if len <> n then exit;
  cur:=0;
  for i:=1 to len-1 do
    if a[i] = a[i+1] then inc(cur);
  if cur < min then
  begin
    min:=cur;
    mlen:=len;
    for i:=1 to mlen do ans[i]:=a[i];
  end;
end;

begin  
  read(n,r);
  min:=maxlongint;
  mlen:=0;
  for z:=1 to r do
  begin
    go(z,r);
    go(r,z);
  end;
  if min = maxlongint then writeln('IMPOSSIBLE') else
  begin
    writeln(min);
    for i:=mlen downto 1 do write(ans[i]);
  end;
  writeln;
end.
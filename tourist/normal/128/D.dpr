{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  q,n,odd,even,i,min,max: longint;
  a,b: array [0..200010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  odd:=0; even:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i] and 1 = 1 then inc(odd)
    else inc(even);
  end;
  if odd <> even then
  begin
    writeln('NO');
    halt;
  end;
  min:=a[1];
  for i:=2 to n do
    if a[i] < min then min:=a[i];
  for i:=1 to n do dec(a[i],min-1);
  for i:=1 to n do
    if a[i] > n then
    begin
      writeln('NO');
      halt;
    end;
  fillchar(b,sizeof(b),0);
  for i:=1 to n do inc(b[a[i]]);
  max:=0;
  for i:=1 to n do
    if a[i] > max then max:=a[i];
  inc(b[1]);
  inc(b[max]);
  for i:=1 to max do
  begin
    dec(b[i],2);
    if b[i] < 0 then
    begin
      writeln('NO');
      halt;
    end;
  end;
  q:=b[1];
  for i:=2 to max do
  begin
    q:=b[i]-q;
    if q < 0 then
    begin
      writeln('NO');
      halt;
    end;
  end;
  writeln('YES');
  close(input);
  close(output);
end.
{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{APPTYPE CONSOLE}
{$M 100000000}
var
  st: ansistring;
  c0,c1,c00,c01,c11: boolean;

function go(l:longint;var c0,c1,c00,c01,c11:boolean):longint;
var
  r: longint;
  l0,l1,l00,l01,l11,r0,r1,r00,r01,r11: boolean;
  ch: char;
begin
  c0:=False; c1:=False;
  c00:=False; c01:=False; c11:=False;
  if st[l] <> '(' then
  begin
    if st[l] = '0' then begin c0:=True; c00:=True; end else
    if st[l] = '1' then begin c1:=True; c11:=True; end
    else begin c0:=True; c1:=True; c01:=True; end;
    go:=l;
    exit;
  end;
  r:=go(l+1,l0,l1,l00,l01,l11);
  ch:=st[r+1];
  r:=go(r+2,r0,r1,r00,r01,r11);
  if ch = '&' then
  begin
    if l0 or r0 then c0:=True;
    if l1 and r1 then c1:=True;
    if l00 or r00 or (l01 and r01) then c00:=True;
    if (l01 and r01) or (l01 and r11) or (l11 and r01) then c01:=True;
    if l11 and r11 then c11:=True;
  end else
  if ch = '|' then
  begin
    if l0 and r0 then c0:=True;
    if l1 or r1 then c1:=True;
    if l00 and r00 then c00:=True;
    if (l00 and r01) or (l01 and r00) or (l01 and r01) then c01:=True;
    if l11 or r11 or (l01 and r01) then c11:=True;
  end else
  begin
    if (l0 and r0) or (l1 and r1) then c0:=True;
    if (l0 and r1) or (l1 and r0) then c1:=True;
    if (l00 and r00) or (l01 and r01) or (l11 and r11) then c00:=True;
    if (l00 and r01) or (l11 and r01) or (l01 and r00) or (l01 and r11) then c01:=True;
    if (l00 and r11) or (l01 and r01) or (l11 and r00) then c11:=True;
  end;
  go:=r+1;
end;

begin  
  readln;
  readln(st);
  go(1,c0,c1,c00,c01,c11);
  if c0 and c1 and c01 then writeln('YES')
  else writeln('NO');
end.
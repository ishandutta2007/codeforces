{R+,S+,Q-,I+,O-}
{$R-,S-,Q-,I-,O+}
const co = 198159127;
var
  len,n,m,i,ri,rj,k,t: longint;
  a,b: array [0..1000010] of char;
  c: array [0..2000010] of char;
  pr: array [0..2000010] of longint;
  ha,hb,pw: array [0..1000010] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  n:=0;
  while True do
  begin
    inc(n);
    read(a[n]);
    if (a[n] < ' ') or (a[n] > Chr(126)) then
    begin
      dec(n);
      break;
    end;
  end;
  m:=1;
  read(b[m]);
  while (b[m] < ' ') or (b[m] > Chr(126)) do read(b[m]);
  while True do
  begin
    inc(m);
    read(b[m]);
    if (b[m] < ' ') or (b[m] > Chr(126)) then
    begin
      dec(m);
      break;
    end;
  end;
  if n <> m then writeln('-1 -1') else
  begin
    ha[0]:=0;
    for i:=1 to n do ha[i]:=ha[i-1]*co+Ord(a[i]);
    hb[0]:=0;
    for i:=1 to n do hb[i]:=hb[i-1]*co+Ord(b[i]);
    pw[0]:=1;
    for i:=1 to n do pw[i]:=pw[i-1]*co;
    for i:=1 to n do c[i]:=a[n-i+1];
    c[n+1]:=#13;
    for i:=n+2 to n+n+1 do c[i]:=b[i-n-1];
    pr[1]:=0; k:=0;
    for i:=2 to n+n+1 do
    begin
      while (k > 0) and (c[i] <> c[k+1]) do k:=pr[k];
      if c[i] = c[k+1] then inc(k);
      pr[i]:=k;
    end;
    ri:=-1; rj:=-1;
    for i:=1 to n-1 do
    begin
      if a[i] <> b[n-i+1] then break;
      t:=pr[n+1+n-i];
      if t = 0 then continue;
      len:=n-i-t;
      if ha[i+len]-ha[i]*pw[len] <> hb[len] then continue;
      ri:=i-1; rj:=i+len;
    end;
    writeln(ri,' ',rj);
  end;
  close(input);
  close(output);
end.
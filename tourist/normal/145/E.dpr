{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  n,m,i,ll,rr: longint;
  inv: array [0..4444444] of boolean;
  a,a4,a7,m4,m7: array [0..4444444] of longint;
  cc,ch: char;

procedure recalc(x:longint);
var
  q: longint;
begin
  a4[x]:=a4[x+x]+a4[x+x+1];
  a7[x]:=a7[x+x]+a7[x+x+1];
  m4[x]:=m4[x+x]+a7[x+x+1];
  q:=a4[x+x]+m4[x+x+1];
  if q > m4[x] then m4[x]:=q;
  m7[x]:=m7[x+x]+a4[x+x+1];
  q:=a7[x+x]+m7[x+x+1];
  if q > m7[x] then m7[x]:=q;
end;

procedure build(x,l,r:longint);
begin
  if l = r then
  begin
    a4[x]:=0; a7[x]:=0;
    m4[x]:=1; m7[x]:=1;
    if a[l] = 4 then inc(a4[x])
    else inc(a7[x]);
    inv[x]:=False;
  end else
  begin
    build(x+x,l,(l+r) shr 1);
    build(x+x+1,(l+r) shr 1+1,r);
    recalc(x);
  end;
end;

procedure modify(x,l,r,ll,rr:longint);
var
  tmp: longint;
begin
  if (l >= ll) and (r <= rr) then
  begin
    inv[x]:=not inv[x];
    tmp:=a4[x]; a4[x]:=a7[x]; a7[x]:=tmp;
    tmp:=m4[x]; m4[x]:=m7[x]; m7[x]:=tmp;
  end else
  begin
    if inv[x] then
    begin
      inv[x+x]:=not inv[x+x];
      tmp:=a4[x+x]; a4[x+x]:=a7[x+x]; a7[x+x]:=tmp;
      tmp:=m4[x+x]; m4[x+x]:=m7[x+x]; m7[x+x]:=tmp;
      inv[x+x+1]:=not inv[x+x+1];
      tmp:=a4[x+x+1]; a4[x+x+1]:=a7[x+x+1]; a7[x+x+1]:=tmp;
      tmp:=m4[x+x+1]; m4[x+x+1]:=m7[x+x+1]; m7[x+x+1]:=tmp;
      inv[x]:=False;
    end;
    if ll <= (l+r) shr 1 then modify(x+x,l,(l+r) shr 1,ll,rr);
    if rr > (l+r) shr 1 then modify(x+x+1,(l+r) shr 1+1,r,ll,rr);
    recalc(x);
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
  begin
    read(ch);
    if ch = '4' then a[i]:=4
    else a[i]:=7;
  end;
  build(1,1,n);
  for i:=1 to m do
  begin
    read(ch);
    while not (ch in ['c','s']) do read(ch);
    cc:=ch;
    while cc in ['a'..'z'] do read(cc);
    if ch = 'c' then writeln(m4[1]) else
    begin
      read(ll,rr);
      modify(1,1,n,ll,rr);
    end;
  end;
//  close(input);
//  close(output);
end.
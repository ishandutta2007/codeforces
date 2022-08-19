{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 10000000}
const md = 12345;
var
  ans,m,kv,i,j,n,k,ii: longint;
  ok: boolean;
  ch: char;
  s,step,q: int64;
  d: array [0..144,0..1010] of longint;
  good,can: array ['A'..'Z'] of boolean;
  tp: array [0..1010] of char;
  v,e,f,z: array [0..1010] of longint;
  a,b,c: array [0..144,0..144] of longint;

procedure rec(v:longint);
var
  i,j: longint;
begin
  if v = m+1 then
  begin
    inc(n);
    for i:=1 to m do d[n,i]:=e[i];
    exit;
  end;
  for j:=0 to z[v]-1 do
  begin
    e[v]:=j;
    rec(v+1);
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(q,m);
  fillchar(can,sizeof(can),False);
  kv:=0;
  for i:=1 to m do
  begin
    read(ch);
    while not (ch in ['A'..'Z']) do read(ch);
    tp[i]:=ch;
    can[ch]:=True;
    read(z[i]);
    if z[i] > 1 then
    begin
      inc(kv);
      v[kv]:=i;
    end;
  end;
  n:=0;
  rec(1);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    for ch:='A' to 'Z' do
      if can[ch] then
      begin
        for j:=1 to kv do
          if tp[v[j]] = ch then
          begin
            f[j]:=d[i,v[j]]+1;
            if f[j] = z[v[j]] then f[j]:=0;
          end
          else f[j]:=d[i,v[j]];
        for ii:=1 to n do
        begin
          ok:=True;
          for j:=1 to kv do
            if f[j] <> d[ii,v[j]] then
            begin
              ok:=False;
              break;
            end;
          if ok then inc(b[i,ii]);
        end;
      end;
  fillchar(a,sizeof(a),0);
  for i:=1 to n do a[i,i]:=1;
  step:=int64(1) shl 62;
  while step > 0 do
  begin
    for i:=1 to n do
      for j:=1 to n do
      begin
        s:=0;
        for k:=1 to n do s:=s+a[i,k]*a[k,j];
        c[i,j]:=s mod md;
      end;
    a:=c;
    if step and q <> 0 then
    begin
      for i:=1 to n do
        for j:=1 to n do
        begin
          s:=0;
          for k:=1 to n do s:=s+a[i,k]*b[k,j];
          c[i,j]:=s mod md;
        end;
      a:=c;
    end;
    step:=step shr 1;
  end;
  ans:=0;
  for i:=1 to n do
  begin
    fillchar(good,sizeof(good),False);
    for j:=1 to m do
      if d[i,j] = 0 then good[tp[j]]:=True;
    ok:=True;
    for ch:='A' to 'Z' do
      if not good[ch] and can[ch] then
      begin
        ok:=False;
        break;
      end;
    if ok then ans:=(ans+a[1,i]) mod md;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
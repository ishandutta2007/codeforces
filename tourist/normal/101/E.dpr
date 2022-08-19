{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const co = 100;
var
  f,x,y: array [0..20010] of longint;
  ff,pr: array [0..co+10,0..co+10] of longint;
  row: array [0..20010 div co+10,0..20010] of longint;
  col: array [0..20010,0..20010 div co+10] of longint;
  pat: array [0..40010] of char;
  i,j,c,kp,n,m,md: longint;

procedure go(i,j:longint);
var
  rw,cl,ii,jj,qi,qj,c: longint;
begin
  if i = 1 then
  begin
    while j > 1 do
    begin
      inc(kp);
      pat[kp]:='S';
      dec(j);
    end;
    exit;
  end;
  if j = 1 then
  begin
    while i > 1 do
    begin
      inc(kp);
      pat[kp]:='C';
      dec(i);
    end;
    exit;
  end;
  rw:=(i-2) div co+1;
  cl:=(j-2) div co+1;
  ii:=(rw-1)*co+1;
  jj:=(cl-1)*co+1;
  for qi:=0 to i-ii do
    for qj:=0 to j-jj do
      if qi = 0 then ff[qi,qj]:=row[rw,jj+qj] else
      if qj = 0 then ff[qi,qj]:=col[ii+qi,cl] else
      begin
        if ff[qi-1,qj] > ff[qi,qj-1] then
        begin
          ff[qi,qj]:=ff[qi-1,qj];
          pr[qi,qj]:=1;
        end else
        begin
          ff[qi,qj]:=ff[qi,qj-1];
          pr[qi,qj]:=2;
        end;
        c:=x[ii+qi]+y[jj+qj];
        if c >= md then dec(c,md);
        ff[qi,qj]:=ff[qi,qj]+c;
      end;
  qi:=i-ii; qj:=j-jj;
  while (qi > 0) and (qj > 0) do
    if pr[qi,qj] = 1 then
    begin
      inc(kp);
      pat[kp]:='C';
      dec(qi);
    end else
    begin
      inc(kp);
      pat[kp]:='S';
      dec(qj);
    end;
  go(ii+qi,jj+qj);
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,md);
  for i:=1 to n do
  begin
    read(x[i]);
    x[i]:=x[i] mod md;
  end;
  for i:=1 to m do
  begin
    read(y[i]);
    y[i]:=y[i] mod md;
  end;
  for i:=0 to m do f[i]:=0;
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      if f[j-1] > f[j] then f[j]:=f[j-1];
      c:=x[i]+y[j];
      if c >= md then dec(c,md);
      f[j]:=f[j]+c;
    end;
    if i mod co = 1 then
      for j:=1 to m do row[i div co+1,j]:=f[j];
    j:=1;
    while j <= m do
    begin
      col[i,j div co+1]:=f[j];
      inc(j,co);
    end;
  end;
  writeln(f[m]);
  kp:=0;
  go(n,m);
  for i:=kp downto 1 do write(pat[i]);
  writeln;
  close(input);
  close(output);
end.
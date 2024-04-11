{$R-,S-,Q-,I-,O+}
const dx: array [1..4] of longint = (-1,0,1,0);
      dy: array [1..4] of longint = (0,-1,0,1);
      let: string = 'ULDR';
      co = 2;
var
  a: array [0..15,0..21905] of word;
  b: array [0..15,0..21905] of byte;
  lw,xx,nn,mm,k,i,j,n,fin,oldk,ans: longint;
  id: array [0..160,0..160] of longint;
  go: array [0..22510,1..4] of longint;
  x,y: array [0..22510] of longint;
  ch: char;
  q: array [0..100010] of char;
  mask,win: array [0..50010] of byte;

procedure rec(v,w,mq,mw:longint);
var
  j: longint;
begin
  if w = co+1 then
  begin
    a[mq,i]:=v;
    b[mq,i]:=mw;
    exit;
  end;
  for j:=1 to 4 do
    rec(go[v,j],w+1,mq shl 2+j-1,mw shl 1+Ord(go[v,j]=fin));
end;

begin
  readln(nn,mm,k);
  fillchar(id,sizeof(id),0);
  n:=0; fin:=0;
  for i:=1 to nn do
  begin
    for j:=1 to mm do
    begin
      read(ch);
      if ch <> '#' then
      begin
        inc(n);
        x[n]:=i;
        y[n]:=j;
        id[i,j]:=n;
        if ch = 'E' then fin:=n;
      end;
    end;
    readln;
  end;
  if n = 1 then
  begin
    writeln(0);
    halt;
  end;
  for i:=1 to n do
    for j:=1 to 4 do
    begin
      go[i,j]:=id[x[i]+dx[j],y[i]+dy[j]];
      if go[i,j] = 0 then go[i,j]:=i;
    end;
  for i:=1 to n do rec(i,1,0,0);
  oldk:=k;
  for i:=1 to k do read(q[i]);
  while k mod co <> 0 do
  begin
    inc(k);
    q[k]:='U';
  end;
  for i:=1 to k div co do
  begin
    mask[i]:=0;
    for j:=(i-1)*co+1 to i*co do
      mask[i]:=mask[i] shl 2+Pos(q[j],let)-1;
    win[i]:=1 shl co-1;
  end;
  lw:=1;
  for i:=1 to n do
  begin
    xx:=i;
    for j:=1 to lw-1 do
      xx:=a[mask[j],xx];
    for j:=lw to k div co do
    begin
      win[j]:=win[j] and b[mask[j],xx];
      xx:=a[mask[j],xx];
    end;
    while (lw <= k div co) and (win[lw] = 0) do inc(lw);
  end;
  ans:=-1;
  for i:=1 to k div co do
  begin
    for j:=1 to co do
      if win[i] and (1 shl (co-j)) <> 0 then
      begin
        ans:=(i-1)*co+j;
        break;
      end;
    if ans <> -1 then break;
  end;
  if ans > oldk then ans:=-1;
  writeln(ans);
end.
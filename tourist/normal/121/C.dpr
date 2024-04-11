{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  f: array [0..99] of int64;
  n,k,i,j,m,x,y,ans: longint;
  was: array [0..99] of boolean;

procedure rec(w:int64);
begin
  if w <= n-m then
  begin
    inc(ans);
    rec(w*10+4);
    rec(w*10+7);
  end;
end;

function lucky(t:int64):boolean;
begin
  while t > 0 do
  begin
    if (t mod 10 <> 4) and (t mod 10 <> 7) then
    begin
      lucky:=False;
      exit;
    end;
    t:=t div 10;
  end;
  lucky:=True;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  f[0]:=1;
  for i:=1 to 19 do f[i]:=f[i-1]*i;
  read(n,k);
  m:=0;
  for i:=1 to n do
    if f[i] >= k then
    begin
      m:=i;
      break;
    end;
  if m = 0 then
  begin
    writeln('-1');
    halt;
  end;
  ans:=0;
  rec(4); rec(7);
  fillchar(was,sizeof(was),False);
  for i:=1 to m do
  begin
    x:=0; y:=1;
    while k > f[m-i] do
    begin
      k:=k-f[m-i];
      inc(y);
    end;
    for j:=1 to y do
    begin
      inc(x);
      while was[x] do inc(x);
    end;
    was[x]:=True;
    if lucky(n-m+i) and lucky(n-m+x) then inc(ans);
  end;
  writeln(ans);
  close(input);
  close(output);
end.
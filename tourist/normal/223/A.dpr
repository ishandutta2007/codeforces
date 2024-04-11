{$R-,S-,Q-,I-,O+}
var
  s: ansistring;
  sp: array [0..400010] of longint;
  good: array [0..400010] of boolean;
  st: array [0..400010] of char;
  n,i,j,cur,k,ans,ax,ay,e: longint;
begin  
  readln(s);
  n:=length(s);
  for i:=1 to n do good[i]:=False;
  e:=0;
  for i:=1 to n do
    if (s[i] = '(') or (s[i] = '[') then
    begin
      inc(e);
      st[e]:=s[i];
      sp[e]:=i;
    end else
    if e = 0 then continue else
    if (st[e] = '(') and (s[i] = ')') or (st[e] = '[') and (s[i] = ']') then
    begin
      good[i]:=True;
      good[sp[e]]:=True;
      dec(e);
    end
    else e:=0;
  good[n+1]:=False;
  ans:=-1; ax:=0; ay:=0;
  i:=1;
  while i <= n do
  begin
    if not good[i] then
    begin
      inc(i);
      continue;
    end;
    j:=i;
    while (j <= n) and (good[j]) do inc(j);
    cur:=0;
    for k:=i to j-1 do
      if s[k] = '[' then inc(cur);
    if cur > ans then
    begin
      ans:=cur;
      ax:=i;
      ay:=j-1;
    end;
    i:=j;
  end;
  if ans = -1 then writeln(0) else
  begin
    writeln(ans);
    for i:=ax to ay do write(s[i]);
    writeln;
  end;
end.
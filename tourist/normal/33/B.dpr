{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  s,t: ansistring;
  v,ans,n,i: longint;
  sc,fc,ch: char;
  res: array [0..100010] of char;
  cost,g: array ['a'..'z','a'..'z'] of longint;
  best: array ['a'..'z','a'..'z'] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  readln(t);
  if length(s) <> length(t) then
  begin
    writeln(-1);
    halt;
  end;
  read(n);
  for sc:='a' to 'z' do
    for fc:='a' to 'z' do
      if sc <> fc then g[sc,fc]:=1000000000
      else g[sc,fc]:=0;
  for i:=1 to n do
  begin
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    sc:=ch;
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    fc:=ch;
    read(v);
    if v < g[sc,fc] then g[sc,fc]:=v;
  end;
  for ch:='a' to 'z' do
    for sc:='a' to 'z' do
      for fc:='a' to 'z' do
        if g[sc,ch]+g[ch,fc] < g[sc,fc] then g[sc,fc]:=g[sc,ch]+g[ch,fc];
  for sc:='a' to 'z' do
    for fc:='a' to 'z' do
    begin
      best[sc,fc]:=' ';
      cost[sc,fc]:=maxlongint;
      for ch:='a' to 'z' do
        if g[sc,ch]+g[fc,ch] < cost[sc,fc] then
        begin
          cost[sc,fc]:=g[sc,ch]+g[fc,ch];
          best[sc,fc]:=ch;
        end;
    end;
  ans:=0;
  for i:=1 to length(s) do
    if cost[s[i],t[i]] > 1e8 then
    begin
      writeln(-1);
      halt;
    end else
    begin
      inc(ans,cost[s[i],t[i]]);
      res[i]:=best[s[i],t[i]];
    end;
  writeln(ans);
  for i:=1 to length(s) do write(res[i]);
  writeln;
  close(input);
  close(output);
end.
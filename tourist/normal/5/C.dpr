{$R-,S-,Q-,I-,O+}
var
  n,i,e,t,max,ka: longint;
  st: array [0..1000010] of longint;
  good: array [0..1000010] of boolean;
  s: ansistring;
begin
  readln(s);
  n:=length(s);
  fillchar(good,sizeof(good),True);
  e:=0;
  for i:=1 to length(s) do
    if s[i] = '(' then
    begin
      inc(e);
      st[e]:=i;
    end else
    if e > 0 then dec(e)
    else good[i]:=False;
  for i:=1 to e do good[st[i]]:=False;
  t:=0; max:=0; ka:=1;
  good[n+1]:=False;
  for i:=1 to n+1 do
    if good[i] then inc(t) else
    begin
      if t > max then
      begin
        max:=t;
        ka:=0;
      end;
      if (t > 0) and (t = max) then inc(ka);
      t:=0;
    end;
  writeln(max,' ',ka);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const w: array [1..6] of ansistring = ('lios','liala','etr','etra','initis','inites');
var
  ok: boolean;
  i,n,m,j,k,q: longint;
  len: array [0..9] of longint;
  tp: array [0..222222] of longint;
  s: ansistring;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  for i:=1 to 6 do len[i]:=length(w[i]);
  readln(s);
  s:=s+' ';
  n:=length(s);
  m:=0;
  i:=1;
  while i <= n do
  begin
    j:=i;
    while s[j] <> ' ' do inc(j);
    inc(m);
    tp[m]:=0;
    for k:=1 to 6 do
      if j-i >= len[k] then
      begin
        ok:=True;
        for q:=1 to len[k] do
          if s[j-q] <> w[k,len[k]-q+1] then
          begin
            ok:=False;
            break;
          end;
        if ok then
        begin
          tp[m]:=k;
          break;
        end;
      end;
    if tp[m] = 0 then
    begin
      writeln('NO');
      halt;
    end;
    i:=j+1;
  end;
  if m = 1 then writeln('YES') else
  begin
    ok:=True;
    for i:=2 to m do
      if tp[i] and 1 <> tp[1] and 1 then
      begin
        ok:=False;
        break;
      end;
    if not ok then writeln('NO') else
    begin
      j:=0;
      for i:=1 to m do
        if (tp[i] = 3) or (tp[i] = 4) then
        begin
          j:=i;
          break;
        end;
      if j = 0 then writeln('NO') else
      begin
        ok:=True;
        for i:=1 to j-1 do
          if (tp[i] <> 1) and (tp[i] <> 2) then
          begin
            ok:=False;
            break;
          end;
        for i:=j+1 to m do
          if (tp[i] <> 5) and (tp[i] <> 6) then
          begin
            ok:=False;
            break;
          end;
        if not ok then writeln('NO')
        else writeln('YES');
      end;
    end;
  end;
  close(input);
  close(output);
end.
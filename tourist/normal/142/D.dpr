{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  s,it,n,m,k,i,p,xx,yy,j: longint;
  ans: string;
  ch: char;
  a: array [0..11111] of longint;
  ok,oka,okb: boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  p:=0;
  oka:=False; okb:=False;
  for i:=1 to n do
  begin
    xx:=0; yy:=0;
    ok:=False;
    for j:=1 to m do
    begin
      read(ch);
      while not (ch in ['R','-','G']) do read(ch);
      if ch = 'R' then xx:=j;
      if ch = 'G' then yy:=j;
      if ch = '-' then ok:=True;
    end;
    if not ok then continue;
    if (xx > 0) and (yy > 0) then
    begin
      inc(p);
      a[p]:=abs(xx-yy)-1;
    end;
    if xx > 0 then okb:=True;
    if yy > 0 then oka:=True;
  end;
  if m = 1 then ans:='Second' else
  if not oka then ans:='Second' else
  if not okb then ans:='First' else
  if p = 0 then ans:='Draw' else
  begin
    ans:='Second';
    inc(k);
    for it:=1 to 20 do
    begin
      s:=0;
      for i:=1 to p do
      begin
        s:=s+a[i] mod 2;
        a[i]:=a[i] div 2;
      end;
      if s mod k <> 0 then ans:='First';
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  gl,gr: array [0..100010] of boolean;
  a: array [0..100010] of longint;
  s,i,n,cur,k: longint;
  ans: int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  s:=0;
  for i:=1 to n do inc(s,a[i]);
  ans:=0;
  if s mod 3 = 0 then
  begin
    fillchar(gl,sizeof(gl),False);
    fillchar(gr,sizeof(gr),False);
    s:=s div 3;
    cur:=0;
    for i:=1 to n do
    begin
      inc(cur,a[i]);
      if cur = s then gl[i]:=True;
    end;
    cur:=0;
    for i:=n downto 1 do
    begin
      inc(cur,a[i]);
      if cur = s then gr[i]:=True;
    end;
    k:=0;
    for i:=n downto 1 do
    begin
      if gl[i] then inc(ans,k);
      inc(k,Ord(gr[i+1]));
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
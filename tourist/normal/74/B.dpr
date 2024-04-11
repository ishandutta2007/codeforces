{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  dir,n,m,k,i,j,ans,p: longint;
  t,s: ansistring;
  ok: boolean;
  wh: array [0..333] of longint;
  f: array [0..333,0..333] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m,k);
  readln(t);
  readln(s);
  p:=length(s);
  if t = 'to head' then dir:=-1
  else dir:=1;
  wh[0]:=k;
  for i:=1 to p do
  begin
    wh[i]:=wh[i-1]+dir;
    if (wh[i] < 1) or (wh[i] > n) then
    begin
      dir:=-dir;
      wh[i]:=wh[i-1]+dir;
    end;
  end;
  fillchar(f,sizeof(f),False);
  f[0,m]:=True;
  ans:=p;
  for i:=1 to p do
  begin
    if s[i] = '1' then
    begin
      for j:=1 to n do
        if j <> wh[i] then f[i,j]:=True;
    end else
      for j:=1 to n do
        if (j <> wh[i]) and (j <> wh[i-1]) then
          if f[i-1,j] or f[i-1,j-1] or f[i-1,j+1] then
            f[i,j]:=True;
    ok:=False;
    for j:=1 to n do ok:=ok or f[i,j];
    if not ok then
    begin
      ans:=i;
      break;
    end;
  end;
  if ans = p then writeln('Stowaway')
  else writeln('Controller ',ans);
  close(input);
  close(output);
end.
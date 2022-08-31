{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  u,t: longint;
  ok: boolean;
  s: ansistring;

procedure check(s:ansistring);
var
  i: longint;
begin
  if (length(s) < 1) or (length(s) > 16) then ok:=False else
    for i:=1 to length(s) do
      if not (s[i] in ['a'..'z','A'..'Z','0'..'9','_']) then ok:=False;
end;

procedure checkhost(s:ansistring);
begin
  if (length(s) < 1) or (length(s) > 32) then ok:=False else
  begin
    s:=s+'.';
    while Pos('.',s) > 0 do
    begin
      check(Copy(s,1,Pos('.',s)-1));
      Delete(s,1,Pos('.',s));
    end;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  u:=Pos('@',s);
  t:=Pos('/',s);
  ok:=True;
  if u = 0 then writeln('NO') else
  if t = 0 then
  begin
    check(Copy(s,1,u-1));
    checkhost(Copy(s,u+1,10000));
    if ok then writeln('YES')
    else writeln('NO');
  end else
  if t < u then writeln('NO') else
  begin
    check(Copy(s,1,u-1));
    checkhost(Copy(s,u+1,t-u-1));
    check(Copy(s,t+1,10000));
    if ok then writeln('YES')
    else writeln('NO');
  end;
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,ans,d,u: longint;
  s: ansistring;
  c: array [-110..110] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  fillchar(c,sizeof(c),0);
  for i:=1 to 5 do read(c[i]);
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    if s = 'S' then u:=1 else
    if s = 'M' then u:=2
    else u:=length(s)+2;
    ans:=0;
    for d:=0 to 6 do
    begin
      if c[u+d] > 0 then
      begin
        ans:=u+d;
        break;
      end;
      if c[u-d] > 0 then
      begin
        ans:=u-d;
        break;
      end;
    end;
    dec(c[ans]);
    if ans = 1 then writeln('S') else
    if ans = 2 then writeln('M') else
    if ans = 3 then writeln('L') else
    if ans = 4 then writeln('XL') else
    if ans = 5 then writeln('XXL');
  end;
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  need,n,m,i,j,q: longint;
  ans,x,y,len: array [0..1010] of longint;
  was: array [0..1010] of boolean;
  ok: boolean;
begin
  read(n,m);
  for i:=1 to n do read(x[i],y[i]);
  for i:=1 to m do read(len[i]);
  x[0]:=x[n]; y[0]:=y[n];
  x[n+1]:=x[1]; y[n+1]:=y[1];
  for q:=1 downto 0 do
  begin
    fillchar(was,sizeof(was),False);
    ok:=True;
    for i:=1 to n do
      if i and 1 = q then
      begin
        need:=abs(x[i]-x[i-1])+abs(y[i]-y[i-1])+abs(x[i]-x[i+1])+abs(y[i]-y[i+1]);
        ans[i]:=0;
        for j:=1 to m do
          if not was[j] and (len[j] = need) then
          begin
            was[j]:=True;
            ans[i]:=j;
            break;
          end;
        if ans[i] = 0 then
        begin
          ok:=False;
          break;
        end;
      end
      else ans[i]:=-1;
    if ok then
    begin
      writeln('YES');
      for i:=1 to n-1 do write(ans[i],' ');
      writeln(ans[n]);
      halt;
    end;
  end;
  writeln('NO');
end.
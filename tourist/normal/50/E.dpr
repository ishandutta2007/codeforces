{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  i,n,m,b,a: longint;
  c,ans,mx: int64;
  cnt: array [0..10000010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  fillchar(cnt,sizeof(cnt),0);
  ans:=0;
  for b:=1 to n do
  begin
    mx:=int64(b)*b;
    if mx > m then mx:=m;
    ans:=ans+2*mx;
    for a:=b-1 downto 0 do
    begin
      c:=int64(b-a)*(b+a);
      if c > m then break;
      inc(cnt[b-a]);
      inc(cnt[b+a]);
    end;
  end;
  for i:=0 to 2*n do
    if cnt[i] > 1 then dec(ans,cnt[i]-1);
  writeln(ans);
  close(input);
  close(output);
end.
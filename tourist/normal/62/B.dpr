{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  u,tt,qq,n,i,m: longint;
  ans: int64;
  c: char;
  t,s: ansistring;
  cost: array [0..200010,'a'..'z'] of longint;
  last: array ['a'..'z'] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(tt,n);
  readln(s);
  fillchar(last,sizeof(last),0);
  for i:=1 to n do
    for c:='a' to 'z' do cost[i,c]:=inf;
  for i:=1 to n do
  begin
    last[s[i]]:=i;
    for c:='a' to 'z' do
      if last[c] <> 0 then
        if i-last[c] < cost[i,c] then cost[i,c]:=i-last[c];
  end;
  fillchar(last,sizeof(last),0);
  for i:=n downto 1 do
  begin
    last[s[i]]:=i;
    for c:='a' to 'z' do
      if last[c] <> 0 then
        if last[c]-i < cost[i,c] then cost[i,c]:=last[c]-i;
  end;
  for qq:=1 to tt do
  begin
    readln(t);
    m:=length(t);
    ans:=0;
    for i:=1 to m do
    begin
      if i > n then u:=cost[n,t[i]]+i-n
      else u:=cost[i,t[i]];
      if u >= inf then u:=m;
      inc(ans,u);
    end;
    writeln(ans);
  end;
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  c,res,n,j,i,co,x: longint;
  p,ans: array [0..200010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  co:=n+n;
  for i:=1 to co do p[i]:=i;
  for i:=2 to co do
    if p[i] = i then
    begin
      c:=i*i;
      if c > co then break;
      while c <= co do
      begin
        if p[c] = c then p[c]:=i;
        inc(c,i);
      end;
    end;
  fillchar(ans,sizeof(ans),0);
  for i:=n+1 to n+n-1 do
  begin
    x:=i;
    while x > 1 do
    begin
      inc(ans[p[x]]);
      x:=x div p[x];
    end;
  end;
  for i:=1 to n-1 do
  begin
    x:=i;
    while x > 1 do
    begin
      dec(ans[p[x]]);
      x:=x div p[x];
    end;
  end;
  res:=1;
  for i:=1 to n+n do
    for j:=1 to ans[i] do res:=(int64(res)*i) mod md;
  res:=(int64(res)+res-n+md) mod md;
  writeln(res);
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  r,n,i,k,cnt,ans: longint;
  s: ansistring;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n);
  readln(s);
  ans:=maxlongint;
  for r:=1 to n do
  begin
    k:=0;
    for i:=1 to n do
      if s[i] = 'H' then inc(k);
    cnt:=0;
    for i:=1 to k do
      if s[i] = 'T' then inc(cnt);
    if cnt < ans then ans:=cnt;
    cnt:=0;
    for i:=1 to n-k do
      if s[i] = 'H' then inc(cnt);
    if cnt < ans then ans:=cnt;
    s:=Copy(s,2,n)+s[1];
  end;
  writeln(ans);
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  s: ansistring;
  tmp,k,ans,n,i: longint;
  a,b,ch: char;
  cnt: array [#0..#255] of longint;
  good: array [#0..#255] of boolean;
  c: array [#0..#255] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  read(k);
  n:=length(s);
  fillchar(cnt,sizeof(cnt),0);
  for i:=1 to n do inc(cnt[s[i]]);
  for a:='a' to 'z' do c[a]:=a;
  for a:='a' to 'z' do
    for b:=Chr(Ord(a)+1) to 'z' do
      if cnt[a] > cnt[b] then
      begin
        tmp:=cnt[a]; cnt[a]:=cnt[b]; cnt[b]:=tmp;
        ch:=c[a]; c[a]:=c[b]; c[b]:=ch;
      end;
  fillchar(good,sizeof(good),True);
  ans:=0;
  for a:='a' to 'z' do
    if cnt[a] <= k then
    begin
      dec(k,cnt[a]);
      good[c[a]]:=False;
    end
    else inc(ans);
  writeln(ans);
  for i:=1 to n do
    if good[s[i]] then write(s[i]);
  writeln;
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  s: ansistring;
  i: longint;
  ans: int64;
  cnt: array [#0..#255] of int64;
  ch: char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  fillchar(cnt,sizeof(cnt),0);
  for i:=1 to length(s) do inc(cnt[s[i]]);
  ans:=0;
  for ch:=#0 to #255 do inc(ans,cnt[ch]*cnt[ch]);
  writeln(ans);
  close(input);
  close(output);
end.
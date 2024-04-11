{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,p,cnt: longint;
  pr: boolean;
  ch,cc: char;
  ok: array [0..11111] of boolean;
  s: ansistring;
  ans: array [0..11111] of char;
  a: array [#0..#255] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  n:=length(s);
  fillchar(ok,sizeof(ok),False);
  for p:=2 to n div 2 do
  begin
    pr:=True;
    for i:=2 to p-1 do
      if p mod i = 0 then pr:=False;
    if not pr then continue;
    for i:=1 to n do
      if p*i > n then break
      else ok[p*i]:=True;
  end;
  cnt:=0;
  for i:=1 to n do
    if ok[i] then inc(cnt);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do inc(a[s[i]]);
  cc:=' ';
  for ch:='a' to 'z' do
    if a[ch] >= cnt then
    begin
      cc:=ch;
      break;
    end;
  if cc = ' ' then writeln('NO') else
  begin
    for i:=1 to n do
      if ok[i] then
      begin
        ans[i]:=cc;
        dec(a[cc]);
      end;
    for i:=1 to n do
      if not ok[i] then
        for ch:='a' to 'z' do
          if a[ch] > 0 then
          begin
            ans[i]:=ch;
            dec(a[ch]);
            break;
          end;
    writeln('YES');
    for i:=1 to n do write(ans[i]);
    writeln;
  end;
  close(input);
  close(output);
end.
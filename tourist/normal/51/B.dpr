{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,m,e,j,tmp: longint;
  st,ans: array [0..10010] of longint;
  c: array [0..10010] of char;
  ch: char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  n:=0;
  while not eof(input) do
  begin
    read(ch);
    if ch in ['a'..'z','<','>','/'] then
    begin
      inc(n);
      c[n]:=ch;
    end;
  end;
  fillchar(ans,sizeof(ans),0);
  m:=0; e:=0;
  for i:=1 to n do
    if c[i] = 'a' then
    begin
      if c[i-2] = '/' then dec(e) else
      begin
        inc(m);
        inc(e);
        st[e]:=m;
      end;
    end else
    if (c[i] = 'd') and (c[i-2] = '<') then inc(ans[st[e]]);
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if ans[i] > ans[j] then
      begin
        tmp:=ans[i];
        ans[i]:=ans[j];
        ans[j]:=tmp;
      end;
  for i:=1 to m-1 do write(ans[i],' ');
  writeln(ans[m]);
  close(input);
  close(output);
end.
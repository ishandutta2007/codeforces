{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j: longint;
  ok: boolean;
  tmp: string;
  ch: char;
  kv,kg,pg: array ['A'..'Z'] of longint;
  g: array ['A'..'Z',0..1010] of string;
  a,b: array [0..1010] of string;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n);
  for i:=1 to n do readln(a[i]);
  for i:=1 to n do readln(b[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i] > a[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if b[i] > b[j] then
      begin
        tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
      end;
  fillchar(kg,sizeof(kg),0);
  fillchar(pg,sizeof(pg),0);
  for i:=1 to n do
  begin
    inc(kg[b[i,1]]);
    g[b[i,1],kg[b[i,1]]]:=b[i];
  end;
  fillchar(kv,sizeof(kv),0);
  for i:=1 to n do inc(kv[a[i,1]]);
  for i:=1 to n do
  begin
    write(a[i],' ');
    if pg[a[i,1]]+kv[a[i,1]] > kg[a[i,1]] then
    begin
      ok:=False;
      for ch:='A' to pred(a[i,1]) do
        if pg[ch]+kv[ch] < kg[ch] then
        begin
          inc(pg[ch]);
          write(g[ch,pg[ch]]);
          ok:=True;
          break;
        end;
      if ok then
      begin
        dec(kv[a[i,1]]);
        if i < n then write(', ');
        continue;
      end;
    end;
    dec(kv[a[i,1]]);
    if pg[a[i,1]] < kg[a[i,1]] then
    begin
      inc(pg[a[i,1]]);
      write(g[a[i,1],pg[a[i,1]]]);
    end else
      for ch:='A' to 'Z' do
        if pg[ch]+kv[ch] < kg[ch] then
        begin
          inc(pg[ch]);
          write(g[ch,pg[ch]]);
          break;
        end;
    if i < n then write(', ');
  end;
  writeln;
  close(input);
  close(output);
end.
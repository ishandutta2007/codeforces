{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  s: ansistring;
  m,mm,len,k,n,i,j,t: longint;
  ch,cc: char;
  last: array ['a'..'z'] of longint;
  pred,a,aa: array [0..200010] of longint;
  b: array [0..200010] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  read(k);
  n:=length(s);
  if int64(n)*(n+1) div 2 < k then
  begin
    writeln('No such line.');
    halt;
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to n do
  begin
    pred[i]:=last[s[i]];
    last[s[i]]:=i;
  end;
  cc:=' ';
  for ch:='a' to 'z' do
  begin
    t:=0;
    j:=last[ch];
    while j > 0 do
    begin
      t:=t+(n-j+1);
      if t >= k then break;
      j:=pred[j];
    end;
    if t >= k then
    begin
      write(ch);
      cc:=ch;
      break;
    end;
    dec(k,t);
  end;
  m:=0;
  j:=last[cc];
  while j > 0 do
  begin
    inc(m);
    a[m]:=j;
    j:=pred[j];
  end;
  for len:=2 to n do
  begin
    if m >= k then break;
    dec(k,m);
    fillchar(last,sizeof(last),0);
    for i:=1 to m do
      if a[i]+len-1 <= n then
      begin
        b[i]:=s[a[i]+len-1];
        pred[i]:=last[b[i]];
        last[b[i]]:=i;
      end
      else b[i]:=' ';
    cc:=' ';
    for ch:='a' to 'z' do
    begin
      t:=0;
      j:=last[ch];
      while j > 0 do
      begin
        t:=t+(n-a[j]-len+2);
        if t >= k then break;
        j:=pred[j];
      end;
      if t >= k then
      begin
        write(ch);
        cc:=ch;
        break;
      end;
      dec(k,t);
    end;
    mm:=0;
    for i:=1 to m do
      if b[i] = cc then
      begin
        inc(mm);
        aa[mm]:=a[i];
      end;
    m:=mm;
    for i:=1 to m do a[i]:=aa[i];
  end;
  writeln;
  close(input);
  close(output);
end.
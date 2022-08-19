{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  kc,kv,co,i,j,tmp,n: longint;
  ans,z: int64;
  flag: boolean;
  b,c,v: array [0..100010] of char;
  a: array [0..100010] of longint;
  ch: char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(z,ch);
  while not (ch in ['0'..'9','+','a','*','+','-']) do read(ch);
  kc:=0;
  while ch in ['0'..'9','+','a','*','+','-'] do
  begin
    inc(kc);
    c[kc]:=ch;
    read(ch);
  end;
  kv:=1; v[1]:='+';
  i:=1;
  while i <= kc do
    if c[i] <> 'a' then
    begin
      inc(kv);
      v[kv]:=c[i];
      inc(i);
    end else
    if (kv >= 2) and (v[kv] = '+') and (v[kv-1] = '+') then
    begin
      dec(kv);
      v[kv]:='b';
      inc(i);
    end else
    begin
      inc(kv);
      v[kv]:='c';
      inc(i,3);
    end;
  i:=1; n:=0;
  while i <= kv do
  begin
    if v[i] = '+' then flag:=False
    else flag:=True;
    inc(i);
    if v[i] in ['b','c'] then co:=1 else
    begin
      co:=0;
      while v[i] in ['0'..'9'] do
      begin
        co:=co*10+Ord(v[i])-48;
        inc(i);
      end;
      inc(i);
    end;
    if flag then co:=-co;
    inc(n);
    a[n]:=co;
    b[n]:=v[i];
    inc(i);
  end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i] > a[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
        ch:=b[i]; b[i]:=b[j]; b[j]:=ch;
      end;
  ans:=0;
  for i:=1 to n do
  begin
    if b[i] = 'b' then inc(z);
    ans:=ans+a[i]*z;
    if b[i] = 'c' then inc(z);
  end;
  writeln(ans);
  close(input);
  close(output);
end.
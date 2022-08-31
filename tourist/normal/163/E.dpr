{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  id,qq,kw,nn,tt,n,i,t,j: longint;
  ans: int64;
  st,fin: array [0..100010] of longint;
  ok: array [0..100010] of boolean;
  a: array [0..1000010,'a'..'z'] of longint;
  pz,fn,s,pred,last,de,pv,u: array [0..1000010] of longint;
  pc: array [0..1000010] of char;
  ch: char;

procedure rec(v:longint);
var
  j: longint;
begin
  inc(kw);
  pz[v]:=kw;
  if u[v] > 0 then st[u[v]]:=kw;
  j:=last[v];
  while j > 0 do
  begin
    rec(j);
    j:=pred[j];
  end;
  if u[v] > 0 then fin[u[v]]:=kw;
end;

procedure modify(x,v:longint);
begin
  while x <= n do
  begin
    inc(s[x],v);
    x:=(x or (x-1))+1;
  end;
end;

function findsum(x:longint):longint;
var
  r: longint;
begin
  r:=0;
  while x > 0 do
  begin
    r:=r+s[x];
    x:=x and (x-1);
  end;
  findsum:=r;
end;

begin
  read(tt,nn);
  fillchar(a,sizeof(a),0);
  n:=1;
  pv[1]:=1;
  pc[1]:='a';
  de[1]:=1;
  u[1]:=0;
  for i:=1 to nn do
  begin
    read(ch);
    while (ch < 'a') or (ch > 'z') do read(ch);
    t:=1;
    while (ch >= 'a') and (ch <= 'z') do
    begin
      if a[t,ch] = 0 then
      begin
        inc(n);
        pv[n]:=t;
        pc[n]:=ch;
        de[n]:=de[t]+1;
        u[n]:=0;
        a[t,ch]:=n;
      end;
      t:=a[t,ch];
      read(ch);
    end;
    u[t]:=i;
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to n do
  begin
    pred[i]:=last[de[i]];
    last[de[i]]:=i;
  end;
  fn[1]:=1;
  for i:=2 to n do
  begin
    j:=last[i];
    while j > 0 do
    begin
      fn[j]:=fn[pv[j]];
      while (fn[j] > 1) and (a[fn[j],pc[j]] = 0) do fn[j]:=fn[fn[j]];
      if a[fn[j],pc[j]] > 0 then fn[j]:=a[fn[j],pc[j]];
      if fn[j] = j then fn[j]:=1;
      j:=pred[j];
    end;
  end;
  fillchar(last,sizeof(last),0);
  for i:=2 to n do
  begin
    pred[i]:=last[fn[i]];
    last[fn[i]]:=i;
  end;
  for i:=1 to n do pz[i]:=0;
  rec(1);
  fillchar(s,sizeof(s),0);
  for i:=1 to nn do
  begin
    modify(st[i],1);
    modify(fin[i]+1,-1);
    ok[i]:=True;
  end;
  for qq:=1 to tt do
  begin
    read(ch);
    while not (ch in ['?','+','-']) do read(ch);
    if ch = '+' then
    begin
      read(id);
      if ok[id] then continue;
      ok[id]:=True;
      modify(st[id],1);
      modify(fin[id]+1,-1);
    end else
    if ch = '-' then
    begin
      read(id);
      if not ok[id] then continue;
      ok[id]:=False;
      modify(st[id],-1);
      modify(fin[id]+1,1);
    end else
    begin
      read(ch);
      while (ch < 'a') or (ch > 'z') do read(ch);
      t:=1; ans:=0;
      while (ch >= 'a') and (ch <= 'z') do
      begin
        while (t > 1) and (a[t,ch] = 0) do t:=fn[t];
        if a[t,ch] > 0 then t:=a[t,ch];
        ans:=ans+findsum(pz[t]);
        read(ch);
      end;
      writeln(ans);
    end;
  end;
end.
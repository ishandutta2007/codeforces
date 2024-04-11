{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  a,need,add,min,cnt: array [0..555555] of longint;
  lucky: boolean;
  i,last,n,m,l,r,v: longint;
  ch: char;

procedure push(x:longint);
begin
  inc(add[x+x],add[x]);
  inc(add[x+x+1],add[x]);
  add[x]:=0;
end;

procedure pull(x:longint);
begin
  min[x]:=min[x+x+1]+add[x+x+1];
  cnt[x]:=cnt[x+x+1];
  if min[x+x]+add[x+x] < min[x] then
  begin
    min[x]:=min[x+x]+add[x+x];
    cnt[x]:=0;
  end;
  if min[x+x]+add[x+x] = min[x] then inc(cnt[x],cnt[x+x]);
end;

procedure build(x,l,r:longint);
begin
  add[x]:=0;
  if l = r then
  begin
    min[x]:=need[a[l]];
    cnt[x]:=1;
  end else
  begin
    build(x+x,l,(l+r) shr 1);
    build(x+x+1,(l+r) shr 1+1,r);
    pull(x);
  end;
end;

procedure doadd(x,l,r,ll,rr,v:longint);
begin
  if (rr < l) or (r < ll) then exit else
  if (l >= ll) and (r <= rr) then dec(add[x],v) else
  begin
    push(x);
    doadd(x+x,l,(l+r) shr 1,ll,rr,v);
    doadd(x+x+1,(l+r) shr 1+1,r,ll,rr,v);
    pull(x);
  end;
end;

procedure find(x,l,r:longint);
begin
  if l = r then
  begin
    a[l]:=a[l]+need[a[l]]-(min[x]+add[x]);
    min[x]:=need[a[l]];
    add[x]:=0;
    exit;
  end;
  push(x);
  if min[x+x]+add[x+x] < 0 then find(x+x,l,(l+r) shr 1)
  else find(x+x+1,(l+r) shr 1+1,r);
  pull(x);
end;

function count(x,l,r,ll,rr:longint):longint;
begin
  if (rr < l) or (r < ll) then count:=0 else
  if (l >= ll) and (r <= rr) then
  begin
    if min[x]+add[x] = 0 then count:=cnt[x]
    else count:=0;
  end else
  begin
    push(x);
    count:=count(x+x,l,(l+r) shr 1,ll,rr)+
           count(x+x+1,(l+r) shr 1+1,r,ll,rr);
    pull(x);
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  last:=0;
  for i:=44444 downto 1 do
  begin
    lucky:=True;
    n:=i;
    while n > 0 do
    begin
      if (n mod 10 <> 4) and (n mod 10 <> 7) then
      begin
        lucky:=False;
        break;
      end;
      n:=n div 10;
    end;
    if lucky then last:=i;
    need[i]:=last-i;
  end;
  read(n,m);
  for i:=1 to n do read(a[i]);
  build(1,1,n);
  for i:=1 to m do
  begin
    read(ch);
    while not (ch in ['c','a']) do read(ch);
    if ch = 'a' then
    begin
      while ch in ['a'..'z'] do read(ch);
      read(l,r,v);
      doadd(1,1,n,l,r,v);
      while min[1]+add[1] < 0 do find(1,1,n);
    end else
    begin
      while ch in ['a'..'z'] do read(ch);
      read(l,r);
      writeln(count(1,1,n,l,r));
    end;
  end;
  close(input);
  close(output);
end.
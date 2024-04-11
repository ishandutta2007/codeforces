{$macro+}
{$define free}

{$ifdef free}
uses math;
{$endif}

const
  maxn=200000;

var
  n,x,a,b,i,m:longint;
  cur,top,next,da,db:array[1..maxn*2]of longint;

procedure dfsa(v,d:longint);
var
  i:longint;
begin
  if da[v]<>-1 then exit;
  da[v]:=d;
  i:=cur[v];
  while i<>0 do
    begin
      dfsa(top[i],d+1);
      i:=next[i]
    end
end;

procedure dfsb(v,d:longint);
var
  i:longint;
begin
  if db[v]<>-1 then exit;
  db[v]:=d;
  i:=cur[v];
  while i<>0 do
    begin
      dfsb(top[i],d+1);
      i:=next[i]
    end
end;

begin
  read(n,x);
{$ifdef free}
  fillchar(cur,sizeof(cur),0);
  fillchar(da,sizeof(da),255);
  fillchar(db,sizeof(db),255);
{$else}
  for i:=1 to n do
    begin
      da[i]:=-1;
      db[i]:=-1
    end;
{$endif}
  for i:=1 to n-1 do
    begin
      read(a,b);
      top[i*2-1]:=b;
      next[i*2-1]:=cur[a];
      cur[a]:=i*2-1;
      top[i*2]:=a;
      next[i*2]:=cur[b];
      cur[b]:=i*2
    end;
  dfsa(1,0);
  dfsb(x,0);
  m:=0;
  for i:=1 to n do
    if da[i]>db[i]
      then m:=max(m,da[i]);
  writeln(m*2)
end.
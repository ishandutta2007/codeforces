{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  ans,h,m,k,h1,m1,h2,m2,lh,lm: int64;
  sw: ansistring;

function count(h1,m1,h2,m2:int64):int64;
var
  i,j: longint;
begin
  j:=0;
  for i:=1 to lh do
  begin
    if h1 mod 10 <> h2 mod 10 then inc(j);
    h1:=h1 div 10;
    h2:=h2 div 10;
  end;
  for i:=1 to lm do
  begin
    if m1 mod 10 <> m2 mod 10 then inc(j);
    m1:=m1 div 10;
    m2:=m2 div 10;
  end;
  count:=j;
end;

function doit(n,k:int64):int64;
var
  i: longint;
begin
  if n = 0 then
  begin
    doit:=0;
    exit;
  end;
  if k <= 0 then
  begin
    doit:=n;
    exit;
  end;
  for i:=1 to k-1 do n:=n div 10;
  doit:=n;
end;

function solve(a,b,k:int64):int64;
begin
  solve:=doit(b,k)-doit(a,k);
end;

function go(h1,m1,h2,m2:int64):int64;
var
  cur: int64;
begin
  if h1 = h2 then cur:=solve(m1,m2,k) else
  begin
    cur:=solve(h1,h2,k-count(0,m-1,0,0));
    cur:=cur+solve(m1,m-1,k);
    cur:=cur+solve(0,m2,k);
    cur:=cur+solve(0,m-1,k)*(h2-h1-1);
  end;
  go:=cur;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(h,m,k,h1,m1,h2,m2);
  str(h,sw);
  lh:=length(sw);
  str(m,sw);
  lm:=length(sw);
  if h1*m+m1 <= h2*m+m2 then ans:=go(h1,m1,h2,m2)
  else ans:=go(h1,m1,h-1,m-1)+go(0,0,h2,m2)+Ord(count(h-1,m-1,0,0) >= k);
  writeln(ans);
  close(input);
  close(output);
end.
{$R-,S-,Q-,I-,O+}
{$M 30000000}
var
  p,len,g,v: array [0..100010] of longint;
  ans,n,m,i,y,a,b,old: longint;
  exit: array [0..100010] of boolean;

function findset(x:longint):longint;
var
  u: longint;
begin
  if x <> p[x] then
  begin
    u:=findset(p[x]);
    len[x]:=len[x]+len[p[x]];
    p[x]:=u;
  end;
  findset:=p[x];
end;

begin
  read(n,m);
  for i:=1 to n do read(g[i]);
  for i:=1 to m do read(v[i]);
  fillchar(exit,sizeof(exit),False);
  for i:=1 to n do
  begin
    p[i]:=i;
    len[i]:=0;
  end;
  old:=0;
  for i:=1 to m do
  begin
    read(b);
    a:=(v[i]+old-1) mod n+1;
    findset(a);
    b:=b-len[a]-1;
    a:=p[a]; ans:=0;
    while b >= 0 do
    begin
      if exit[a] then break;
      inc(ans);
      y:=findset(g[a]);
      if a = y then exit[y]:=True;
      len[a]:=len[a]+len[g[a]]+1;
      p[a]:=y;
      if exit[y] then break;
      b:=b-len[a];
      a:=p[a];
    end;
    writeln(ans);
    old:=ans;
  end;
end.
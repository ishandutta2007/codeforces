{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  mm,n,i,j,m,p: longint;
  s: string;
  a: array [0..88888] of string;
  ss,ff,pred,last,was,pa,pb,b: array [0..88888] of longint;

procedure rec(v,w:longint;sl:string);
begin
  if v = p+1 then
  begin
    if w = 0 then exit;
    inc(m);
    a[m]:=sl;
    b[m]:=i;
    exit;
  end;
  rec(v+1,w,sl);
  if w < 4 then rec(v+1,w+1,sl+s[v]);
end;

function solve(v:longint):boolean;
var
  j: longint;
begin
  if v = 0 then solve:=True else
  if was[v] = i then solve:=False else
  begin
    was[v]:=i;
    j:=last[v];
    while j > 0 do
    begin
      if ff[j] <> pa[v] then
        if solve(pb[ff[j]]) then
        begin
          pa[v]:=ff[j];
          pb[ff[j]]:=v;
          solve:=True;
          exit;
        end;
      j:=pred[j];
    end;
    solve:=False;
  end;
end;

procedure Sort(l,r:longint);
var
  i,j,tt: longint;
  x,tmp: string;
begin
  i:=l; j:=r;
  x:=a[l+random(r-l+1)];
  repeat
    while a[i] < x do inc(i);
    while x < a[j] do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      tt:=b[i]; b[i]:=b[j]; b[j]:=tt;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randomize;
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  readln(n);
  m:=0;
  for i:=1 to n do
  begin
    readln(s);
    p:=length(s);
    rec(1,0,'');
  end;
  Sort(1,m);
  mm:=0; j:=0;
  for i:=1 to m do
  begin
    if (i = 1) or (a[i] <> a[j]) then
    begin
      inc(j);
      a[j]:=a[i];
    end;
    inc(mm);
    ss[mm]:=b[i];
    ff[mm]:=j;
  end;
  m:=j;
  fillchar(last,sizeof(last),0);
  for i:=1 to mm do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(pa,sizeof(pa),0);
  fillchar(pb,sizeof(pb),0);
  fillchar(was,sizeof(was),0);
  for i:=1 to n do
    if not solve(i) then
    begin
      writeln(-1);
      close(input);
      close(output);
      halt;
    end;
  for i:=1 to n do writeln(a[pa[i]]);
  close(input);
  close(output);
end.
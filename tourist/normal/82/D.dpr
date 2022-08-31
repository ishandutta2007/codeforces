{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 20000000}
var
  n,i,j,ans: longint;
  a: array [0..1010] of longint;
  f,p: array [0..1010,0..1010] of longint;

function max(a,b:longint):longint;
begin
  if a > b then max:=a
  else max:=b;
end;

function solve(i,j:longint):longint;
var
  min,cur,kj: longint;
begin
  if j > n then solve:=a[i] else
  if j = n then solve:=max(a[i],a[j]) else
  if f[i,j] > 0 then solve:=f[i,j] else
  begin
    min:=solve(i,j+2)+max(a[j],a[j+1]);
    kj:=1;
    cur:=solve(j,j+2)+max(a[i],a[j+1]);
    if cur < min then begin min:=cur; kj:=2; end;
    cur:=solve(j+1,j+2)+max(a[i],a[j]);
    if cur < min then begin min:=cur; kj:=3; end;
    f[i,j]:=min;
    p[i,j]:=kj;
    solve:=min;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  fillchar(f,sizeof(f),0);
  ans:=solve(1,2);
  writeln(ans);
  i:=1; j:=2;
  while j < n do
  begin
    if p[i,j] = 1 then writeln(j,' ',j+1) else
    if p[i,j] = 2 then
    begin
      writeln(i,' ',j+1);
      i:=j;
    end else
    begin
      writeln(i,' ',j);
      i:=j+1;
    end;
    inc(j,2);
  end;
  if j = n then writeln(i,' ',j)
  else writeln(i);
  close(input);
  close(output);
end.
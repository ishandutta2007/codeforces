{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  n,m,k,ans: longint;
  f,g,t: array [0..11111] of longint;

function go(n,k:longint):longint;
var
  ans,q,i,s: longint;
begin
  fillchar(f,sizeof(f),0);
  f[n]:=1;
  for q:=1 to k do
  begin
    t[n]:=f[n];
    for i:=n-1 downto 1 do
    begin
      t[i]:=t[i+1]+f[i];
      if t[i] >= md then dec(t[i],md);
    end;
    s:=0;
    for i:=n-2 downto 1 do
    begin
      s:=s+t[i+2];
      if s >= md then dec(s,md);
      g[i]:=s;
    end;
    g[n-1]:=0; g[n]:=0;
    for i:=1 to n do f[i]:=g[i];
  end;
  ans:=0;
  for i:=1 to n do
  begin
    inc(ans,f[i]);
    if ans >= md then dec(ans,md);
  end;
  go:=ans;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  ans:=int64(go(n,k))*go(m,k) mod md;
  writeln(ans);
  close(input);
  close(output);
end.
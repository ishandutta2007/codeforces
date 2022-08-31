{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const inf = round(2e18);
var
  f: array [0..222,0..222] of int64;
  n,m,i,j,pp: longint;
  k,c: int64;
  p: array [0..222] of longint;
  s: array [0..222] of char;

function count():int64;
var
  i,j: longint;
begin
  fillchar(f,sizeof(f),0);
  f[1,0]:=1;
  for i:=2 to n+m do
    for j:=0 to i-1 do
    begin
      f[i,j]:=0;
      if s[i] <> '(' then f[i,j]:=f[i-1,j+1];
      if (s[i] <> ')') and (j > 0) then
      begin
        f[i,j]:=f[i,j]+f[i-1,j-1];
        if f[i,j] >= inf then f[i,j]:=inf;
      end;
    end;
  count:=f[n+m,0];
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  for i:=2 to n+m do p[i]:=1000000;
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(pp);
      if pp < p[i+j] then p[i+j]:=pp;
    end;
  for i:=2 to n+m do s[i]:=' ';
  for pp:=1 to n*m do
    for i:=2 to n+m do
      if p[i] = pp then
      begin
        s[i]:='(';
        c:=count();
        if c >= k then continue;
        k:=k-c;
        s[i]:=')';
      end;
  for i:=1 to n do
  begin
    for j:=1 to m do write(s[i+j]);
    writeln;
  end;
  close(input);
  close(output);
end.
{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 10000000}
const md = round(1e9+7);
var
  n,m,k,i,j,t,x,y,cnt,ans: longint;
  r,p: array [0..11111] of longint;

function findset(x:longint):longint;
begin
  if x <> p[x] then p[x]:=findset(p[x]);
  findset:=p[x];
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  for i:=1 to n do p[i]:=i;
  for i:=1 to n-k+1 do
    for j:=i to (i+(i+k-1)-1) shr 1 do
    begin
      t:=i+(i+k-1)-j;
      x:=findset(j);
      y:=findset(t);
      if x <> y then p[x]:=y;
    end;
  for i:=1 to n do r[i]:=findset(i);
  cnt:=0;
  for i:=1 to n do
    for j:=1 to n do
      if r[j] = i then
      begin
        inc(cnt);
        break;
      end;
  ans:=1;
  for i:=1 to cnt do ans:=int64(ans)*m mod md;
  writeln(ans);
//  close(input);
//  close(output);
end.
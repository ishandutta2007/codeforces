{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const inf = round(1e18);
var
  n,i,t,c,j,q: longint;
  f: array [0..2010] of int64;
  ans: int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do f[i]:=inf;
  f[0]:=0;
  ans:=0;
  for i:=1 to n do
  begin
    read(t,c);
    inc(t);
    for j:=n-1 downto 0 do
    begin
      q:=j+t;
      if q > n then q:=n;
      if f[j]+c < f[q] then f[q]:=f[j]+c;
    end;
    inc(ans,c);
  end;
  writeln(f[n]);
  close(input);
  close(output);
end.
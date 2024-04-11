{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,k,i,x,y,ans: longint;
  min: array [0..100010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  for i:=1 to m do min[i]:=maxlongint;
  for i:=1 to n do
  begin
    read(x,y);
    if y < min[x] then min[x]:=y;
  end;
  ans:=0;
  for i:=1 to m do inc(ans,min[i]);
  if ans > k then ans:=k;
  writeln(ans);
  close(input);
  close(output);
end.
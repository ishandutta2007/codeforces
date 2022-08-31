{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  ans: int64;
  n,m,k,i,j,x: longint;
  a,b,c: array [0..100010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  for i:=1 to m do read(a[i],b[i],c[i]);
  ans:=0;
  for i:=1 to k do
  begin
    read(x);
    for j:=1 to m do
      if (x >= a[j]) and (x <= b[j]) then ans:=ans+c[j]+x-a[j];
  end;
  writeln(ans);
  close(input);
  close(output);
end.
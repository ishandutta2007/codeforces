{$R+,S+,Q+,I+,O-}
var
  n,i,v,j: longint;
  ans: int64;
  a: array [0..9] of int64;
begin
  read(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do inc(a[(i-1) mod 9+1]);
  ans:=0;
  for i:=1 to 9 do
    for j:=1 to 9 do inc(ans,a[i]*a[j]*a[(i*j-1) mod 9+1]);
  for i:=1 to n do ans:=ans-n div i;
  writeln(ans);
end.
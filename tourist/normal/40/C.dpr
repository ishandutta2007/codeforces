{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  lg,rg,n,x,m,y,d,i,j: longint;
  ans: int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,x,m,y);
  ans:=n+m+1; d:=abs(x-y);
  for i:=1 to n do
  begin
    j:=d-i+1;
    if (j >= 1) and (j <= m) then inc(ans);
    lg:=j+1; rg:=m;
    if i-d+1 > lg then lg:=i-d+1;
    if i+d-1 < rg then rg:=i+d-1;
    if lg <= rg then inc(ans,(rg-lg+1)*2);
  end;
  writeln(ans);
  close(input);
  close(output);
end.
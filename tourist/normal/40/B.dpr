{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,x,i,j,u,ans: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,x);
  ans:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (i+j) and 1 = 0 then
      begin
        u:=i;
        if j < u then u:=j;
        if n-i+1 < u then u:=n-i+1;
        if m-j+1 < u then u:=m-j+1;
        if u = x then inc(ans);
      end;
  writeln(ans);
  close(input);
  close(output);
end.
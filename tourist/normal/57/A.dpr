{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,x1,y1,x2,y2,ans: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,x1,y1,x2,y2);
  ans:=0;
  while (x1 <> x2) or (y1 <> y2) do
  begin
    inc(ans);
    if (x1 = 0) and (y1 > 0) then dec(y1) else
    if (y1 = 0) and (x1 < n) then inc(x1) else
    if (x1 = n) and (y1 < n) then inc(y1)
    else dec(x1);
  end;
  if 4*n-ans < ans then ans:=4*n-ans;
  writeln(ans);
  close(input);
  close(output);
end.
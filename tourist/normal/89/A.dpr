{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,k,i,max: longint;
  can: int64;
  a: array [0..100010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  for i:=1 to n do read(a[i]);
  if n and 1 = 0 then writeln(0) else
  begin
    max:=1000000;
    for i:=1 to n do
      if i and 1 = 1 then
        if a[i] < max then max:=a[i];
    can:=int64(k)*(m div (n div 2+1));
    if can < max then max:=can;
    writeln(max);
  end;
  close(input);
  close(output);
end.
{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  ans: extended;
  n,m,h,i,s: longint;
  a: array [0..10010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,h);
  for i:=1 to m do read(a[i]);
  s:=0;
  for i:=1 to m do inc(s,a[i]);
  if s < n then
  begin
    writeln('-1.0');
    halt;
  end;
  dec(s); dec(n); dec(a[h]);
  ans:=1;
  for i:=s-n+1 to s do ans:=ans*(i-a[h])/i;
  writeln(1-ans:0:17);
  close(input);
  close(output);
end.
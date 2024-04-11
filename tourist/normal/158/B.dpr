{$R-,S-,Q-,I-,O+}
var
  n,i,x,ans: longint;
  c: array [0..5] of longint;
begin
  read(n);
  fillchar(c,sizeof(c),0);
  for i:=1 to n do
  begin
    read(x);
    inc(c[x]);
  end;
  ans:=c[4]+c[3];
  if c[1] > c[3] then dec(c[1],c[3])
  else c[1]:=0;
  ans:=ans+c[2] div 2;
  c[2]:=c[2] mod 2;
  ans:=ans+(c[2]*2+c[1]+3) div 4;
  writeln(ans);
end.
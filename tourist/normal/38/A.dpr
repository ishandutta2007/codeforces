{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,s,f,q: longint;
  x: array [0..1010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n-1 do read(x[i]);
  read(s,f);
  q:=0;
  for i:=s to f-1 do inc(q,x[i]);
  writeln(q);
  close(input);
  close(output);
end.
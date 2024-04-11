{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  t,n,p,tmp: int64;
  i,j: longint;
  a,b: array [0..1010] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(t,n);
  for i:=1 to n do read(a[i],b[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if b[i] < b[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
        tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
      end;
  p:=0;
  for i:=1 to n do
    if t > a[i] then
    begin
      dec(t,a[i]);
      inc(p,a[i]*b[i]);
    end else
    begin
      inc(p,t*b[i]);
      break;
    end;
  writeln(p);
  close(input);
  close(output);
end.
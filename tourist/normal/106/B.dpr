{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,km: longint;
  a,b,c,d: array [0..100010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i],b[i],c[i],d[i]);
  km:=0; d[0]:=maxlongint;
  for i:=1 to n do
  begin
    for j:=1 to n do
      if (a[i] < a[j]) and (b[i] < b[j]) and (c[i] < c[j]) then d[i]:=maxlongint;
    if d[i] < d[km] then km:=i;
  end;
  writeln(km);
  close(input);
  close(output);
end.
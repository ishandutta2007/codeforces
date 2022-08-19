{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,tmp: longint;
  sum: int64;
  x,c: array [0..3010] of longint;
  f: array [0..3010] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(x[i],c[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if x[i] > x[j] then
      begin
        tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
        tmp:=c[i]; c[i]:=c[j]; c[j]:=tmp;
      end;
  inc(n);
  x[n]:=x[n-1]+1;
  c[n]:=0;
  for i:=1 to n do f[i]:=round(1e18);
  f[1]:=c[1];
  for i:=1 to n do
  begin
    sum:=f[i];
    for j:=i+1 to n do
    begin
      if sum+c[j] < f[j] then f[j]:=sum+c[j];
      sum:=sum+x[j]-x[i];
    end;
  end;
  writeln(f[n]);
  close(input);
  close(output);
end.
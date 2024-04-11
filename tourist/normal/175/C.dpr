{$R-,S-,Q-,I-,O+}
var
  n,i,j,t: longint;
  p,k,c: array [0..11111] of int64;
  tmp,ans,rm: int64;
begin
  read(n);
  for i:=1 to n do read(k[i],c[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if c[i] > c[j] then
      begin
        tmp:=k[i]; k[i]:=k[j]; k[j]:=tmp;
        tmp:=c[i]; c[i]:=c[j]; c[j]:=tmp;
      end;
  read(t);
  for i:=1 to t do read(p[i]);
  j:=1; rm:=p[1];
  ans:=0;
  for i:=1 to n do
  begin
    while k[i] > rm do
    begin
      ans:=ans+rm*c[i]*j;
      k[i]:=k[i]-rm;
      inc(j);
      if j > t then rm:=round(1e12)
      else rm:=p[j]-p[j-1];
    end;
    ans:=ans+k[i]*c[i]*j;
    rm:=rm-k[i];
  end;
  writeln(ans);
end.
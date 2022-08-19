{$R-,S-,Q-,I-,O+}
var
  kp,n,m,k,i,j,c,ans,s: longint;
  a,pred,last,p: array [0..400010] of longint;
begin
  read(n,m,k);
  for i:=1 to n do read(a[i]);
  fillchar(last,sizeof(last),0);
  for i:=n downto 1 do
  begin
    pred[i]:=last[a[i]];
    last[a[i]]:=i;
  end;
  ans:=0;
  for c:=1 to m do
  begin
    kp:=0;
    j:=last[c];
    while j > 0 do
    begin
      inc(kp);
      p[kp]:=j;
      j:=pred[j];
    end;
    if kp = 0 then continue;
    if 1 > ans then ans:=1;
    for i:=kp downto 2 do p[i]:=p[i]-p[i-1]-1;
    j:=1; s:=0;
    for i:=2 to kp do
    begin
      while (j < kp) and (s+p[j+1] <= k) do
      begin
        inc(j);
        inc(s,p[j]);
      end;
      if j-i+2 > ans then ans:=j-i+2;
      dec(s,p[i]);
    end;
  end;
  writeln(ans);
end.
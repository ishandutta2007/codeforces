{$R-,S-,Q-,I-,O+}
var
  tmp,s,min,n,k,i,j: longint;
  c,t,p: array [0..10010] of longint;
  ans: int64;
begin
  read(n,k);
  for i:=1 to n do
  begin
    read(c[i],t[i]);
    p[i]:=i;
  end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (t[i] > t[j]) or (t[i] = t[j]) and (c[i] < c[j]) then
      begin
        tmp:=c[i]; c[i]:=c[j]; c[j]:=tmp;
        tmp:=t[i]; t[i]:=t[j]; t[j]:=tmp;
        tmp:=p[i]; p[i]:=p[j]; p[j]:=tmp;
      end;
  ans:=0;
  for i:=1 to k-1 do
    if t[i] = 1 then ans:=ans+c[i]
    else ans:=ans+c[i]*2;
  min:=maxlongint; s:=0;
  for i:=k to n do
  begin
    if t[i] = 1 then s:=1;
    if c[i] < min then min:=c[i];
    ans:=ans+c[i]*2;
  end;
  if s = 1 then ans:=ans-min;
  writeln(ans div 2,'.',(ans mod 2)*5);
  for i:=1 to k-1 do writeln(1,' ',p[i]);
  write(n-k+1);
  for i:=k to n do write(' ',p[i]);
  writeln;
end.
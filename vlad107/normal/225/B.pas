{$r-,q-,s-,i-,o+}
var
  kans,n,s,k,i:longint;
  ans,f:array[0..500500]of int64;

begin
  read(s,k);
  f[1]:=1;
  f[2]:=1;
  n:=2;
  while (f[n]<=s)do begin
    inc(n);
    f[n]:=2*f[n-1];
    if (n-k-1>=1)then f[n]:=f[n]-f[n-k-1];
  end;
  kans:=0;
  for i:=n downto 0 do 
    if (s>=f[i])then begin
      inc(kans);
      ans[kans]:=f[i];
      s:=s-f[i];
    end;
  writeln(kans);
  for i:=1 to kans do write(ans[i],' ');
  writeln;
end.
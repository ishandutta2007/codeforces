{$r-,q-,s-,i-,o+}
const
  P=131;
  MAXN=5000010;
var
  s:ansistring;
  i:longint;
  s1,s2,s3,res,hs,he:int64;
  a,f:array[0..MAXN]of longint;
begin
  readln(s);
  for i:=1 to length(s)do a[i]:=ord(s[i]);
  f[1]:=1;
  res:=1;
  hs:=0;he:=0;
  s1:=1;s2:=1;s3:=1;
  for i:=2 to length(s) do begin
    if (i and 1=1)
      then begin
        dec(he,s1*a[(i+1) shr 1]);
        s1:=s1*P;
      end else hs:=hs*P+a[i shr 1];
    he:=he+a[i]*s2;
    s2:=s2*P;
    if (i and 1=1)then s3:=s3*P;
    if (hs*s3=he)
      then f[i]:=f[i shr 1]+1
      else f[i]:=0;
    inc(res,f[i]);
  end;
  writeln(res);
end.
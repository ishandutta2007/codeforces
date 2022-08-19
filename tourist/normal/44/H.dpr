{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,d,p: longint;
  ok: boolean;
  s: ansistring;
  ans: int64;
  f: array [0..1010,0..10] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  n:=length(s);
  fillchar(f,sizeof(f),0);
  for d:=0 to 9 do f[1,d]:=1;
  for i:=1 to n-1 do
    for d:=0 to 9 do
    begin
      p:=d+Ord(s[i+1])-48;
      inc(f[i+1,p shr 1],f[i,d]);
      if p and 1 = 1 then inc(f[i+1,(p+1) shr 1],f[i,d]);
    end;
  ans:=0;
  for d:=0 to 9 do inc(ans,f[n,d]);
  ok:=True;
  for i:=2 to length(s) do
    if abs(Ord(s[i])-Ord(s[i-1])) > 1 then ok:=False;
  if ok then dec(ans);
  writeln(ans);
  close(input);
  close(output);
end.
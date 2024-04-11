{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,i,j,k,t,nk: longint;
  ans,p: extended;
  f: array [0..55,0..55,0..55] of extended;
  pw: array [0..55,0..55] of extended;
  c: array [0..55,0..55] of int64;
  a: array [0..55] of longint;
begin
  fillchar(c,sizeof(c),0);
  for i:=0 to 50 do c[i,0]:=1;
  for i:=1 to 50 do
    for j:=1 to i do c[i,j]:=c[i-1,j]+c[i-1,j-1];
  read(n,m);
  for i:=1 to m do read(a[i]);
  fillchar(pw,sizeof(pw),0);
  for i:=0 to 50 do
  begin
    pw[i,0]:=1.0;
    for j:=1 to 50 do pw[i,j]:=pw[i,j-1]*i;
  end;
  fillchar(f,sizeof(f),0);
  f[1,n,0]:=1;
  for i:=1 to m do
    for j:=n downto 0 do
      for k:=0 to n do
        if f[i,j,k] > 0 then
          for t:=0 to j do
          begin
            p:=f[i,j,k]*pw[m-i,j-t]/pw[m-i+1,j]*c[j,t];
            nk:=(t+a[i]-1) div a[i];
            if k > nk then nk:=k;
            f[i+1,j-t,nk]:=f[i+1,j-t,nk]+p;
          end;
  ans:=0;
  for k:=0 to n do ans:=ans+f[m+1,0,k]*k;
  writeln(ans:0:17);
end.
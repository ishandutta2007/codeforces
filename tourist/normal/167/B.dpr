{$R-,S-,Q-,I-,O+}
var
  z,n,l,k,i,j,q,nq: longint;
  p: array [0..202] of extended;
  a: array [0..202] of longint;
  f: array [0..202,0..202,-202..202] of extended;
  ans: extended;
begin
  read(n,l,k);
  for i:=1 to n do
  begin
    read(z);
    p[i]:=0.01*z;
  end;
  for i:=1 to n do read(a[i]);
  if k > n then k:=n;
  fillchar(f,sizeof(f),0);
  f[1,0,k]:=1;
  for i:=1 to n do
    for j:=0 to i-1 do
      for q:=-n to n do
        if f[i,j,q] > 0 then
        begin
          f[i+1,j,q]:=f[i+1,j,q]+f[i,j,q]*(1-p[i]);
          nq:=q+a[i];
          if nq > n then nq:=n;
          if nq < -n then nq:=-n;
          f[i+1,j+1,nq]:=f[i+1,j+1,nq]+f[i,j,q]*p[i];
        end;
  ans:=0;
  for j:=l to n do
    for q:=0 to n do ans:=ans+f[n+1,j,q];
  writeln(ans:0:17);
end.
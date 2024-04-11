{$R-,S-,Q-,I-,O+}
const c = 10000;
var
  s,ans: int64;
  i,n,x,y: longint;
  a,b: array [-10010..10010] of int64;
begin
  read(n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
  begin
    read(x,y);
    inc(a[x]);
    inc(b[y]);
  end;
  ans:=0;
  for i:=-c to c do ans:=ans+2*i*i*(a[i]+b[i])*n;
  s:=0;
  for i:=-c to c do s:=s+i*a[i];
  for i:=-c to c do ans:=ans-2*s*i*a[i];
  s:=0;
  for i:=-c to c do s:=s+i*b[i];
  for i:=-c to c do ans:=ans-2*s*i*b[i];
  writeln(ans div 2);
end.
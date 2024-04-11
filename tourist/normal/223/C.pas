{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  n,k,i,j,ans: longint;
  c,a: array [0..2222] of longint;

function inv(a:longint):longint;
var
  x,step: longint;
begin
  x:=1; step:=1 shl 30;
  while step > 0 do
  begin
    x:=int64(x)*x mod md;
    if step and (md-2) <> 0 then x:=int64(x)*a mod md;
    step:=step shr 1;
  end;
  inv:=x;
end;

begin  
  read(n,k);
  for i:=1 to n do read(a[i]);
  c[0]:=1;
  for i:=1 to n do c[i]:=int64(c[i-1])*(k+i-1) mod md*inv(i) mod md;
  for i:=1 to n do
  begin 
    ans:=0;
    for j:=1 to i do ans:=(ans+int64(a[j])*c[i-j]) mod md;
    write(ans);
    if i < n then write(' ');
  end;
  writeln;
end.
var n,i,g:integer;
l,r,m,ql,qr,t:int64;
a,b:array [0..100100] of int64;

begin
readln(n,l,r,ql,qr);
b[0]:=0;
for i:=1 to n do
  begin
  read(a[i]);
  b[i]:=b[i-1]+a[i];
  end;
m:=10000000000000000;
for i:=0 to n do
  begin
  g:=n-2*i;
  if g>=1 then t:=(g-1)*qr+l*b[i]+r*(b[n]-b[i]) else
    begin
    if g<0 then t:=(abs(g)-1)*ql else t:=0;
    t+=l*b[i]+r*(b[n]-b[i]);
    end;
  if t<m then m:=t;
  end;
writeln(m);
end.
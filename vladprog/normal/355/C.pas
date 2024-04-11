uses math;

var
  n,l,r,ql,qr,i,s,m:longint;
  w:array[1..100000]of longint;

{function min1(a,b:longint):longint;
begin
  min1:=min(a,b)
end;

function min(a,b:longint):longint;
begin
  writeln(i,' ',b);
  min:=min1(a,b)
end;}

begin
  read(n,l,r,ql,qr);
  for i:=1 to n do
    begin
      read(w[i]);
      inc(s,w[i]*r)
    end;
  //writeln(0,' ',s+qr*(n-1));
  m:=s+qr*(n-1);
  for i:=1 to n do
    begin
      inc(s,w[i]*(l-r));
      if abs(n-2*i)<=1
        then m:=min(m,s)
        else m:=min(m,s+ql*max(0,2*i-n-1)+qr*max(0,n-2*i-1))
    end;
  writeln(m)
end.
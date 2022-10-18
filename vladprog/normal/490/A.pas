uses math;

var
  n,i,t,w:longint;
  a:array[1..3,0..5000]of longint;

begin
  read(n);
  for i:=1 to n do
    begin
      read(t);
      inc(a[t,0]);
      a[t,a[t,0]]:=i
    end;
  w:=min(min(a[1,0],a[2,0]),a[3,0]);
  writeln(w);
  for i:=1 to w do
    writeln(a[1,i],' ',a[2,i],' ',a[3,i])
end.
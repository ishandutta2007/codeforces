{$macro+}
{$define free}

{$ifdef free}
uses math;
{$endif}

function p(n:int64):int64;
begin
  p:=n*(n+1)div 2
end;

function sum(x,y:int64):int64;
begin
  sum:=p(x)*(y+1)+p(y)*(x+1)
end;

var
  i:longint;
  m,b,maxx:int64;

begin
  read(m,b);
  maxx:=0;
  for i:=0 to b do
    maxx:=max(maxx,sum(i*m,b-i));
  writeln(maxx)
end.
const
  m=1000000007;

function pow(n:uint64):uint64;
var
  p:uint64;
begin
  case n of
    0:pow:=1;
    1:pow:=2;
    else
      begin
        p:=pow(n shr 1);
        pow:=(p*p*pow(n and 1))mod m
      end
  end
end;

var
  k,n:uint64;
  c:char;

begin
  k:=0;
  n:=0;
  while not eoln do
    begin
      read(c);
      if c='a'
        then inc(k)
        else n:=(n+pow(k)-1) mod m
    end;
  writeln(n)
end.
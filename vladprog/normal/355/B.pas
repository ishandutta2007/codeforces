{procedure inc1(var a:longint;b:longint);
begin
  inc(a,b)
end;

procedure inc(var a:longint;b:longint);
begin
  inc1(a,b);
  writeln(b)
end;}

var
  c1,c2,c3,c4,n,m,c,a,b,i,s:longint;

begin
  read(c1,c2,c3,c4,n,m);
  for i:=1 to n do
    begin
      read(c);
      if c*c1<c2
        then inc(a,c*c1)
        else inc(a,c2)
    end;
  //writeln;
  if a<c3
    then inc(s,a)
    else inc(s,c3);
  //writeln;
  for i:=1 to m do
    begin
      read(c);
      if c*c1<c2
        then inc(b,c*c1)
        else inc(b,c2)
    end;
  //writeln;
  if b<c3
    then inc(s,b)
    else inc(s,c3);
  //writeln;
  if s<c4
    then writeln(s)
    else writeln(c4)
end.
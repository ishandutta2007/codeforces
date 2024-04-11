const a:array[1..12] of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
var i,j,x1,x2:longint;
    s1,s2:string;
function tryit(x:string):longint;
var i:longint;
begin
  if (x='monday') then exit(1);
  if (x='tuesday') then exit(2);
  if (x='wednesday') then exit(3);
  if (x='thursday') then exit(4);
  if (x='friday') then exit(5);
  if (x='saturday') then exit(6);
  if (x='sunday') then exit(7);
end;
begin
  readln(s1);
  readln(s2);
  x1:=tryit(s1);
  x2:=tryit(s2);
  for i:=1 to 11 do
  begin
    if (a[i] mod 7=(x2-x1+7) mod 7) then
    begin
      writeln('YES');
      halt;
    end;
  end;
  writeln('NO');
end.
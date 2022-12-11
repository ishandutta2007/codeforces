var now:longint;
function flag(x:longint):boolean;
var i:longint;
begin
  for i:=2 to trunc(sqrt(x)) do
	if (x mod i=0) then exit(false);
  exit(true);
end;
begin
  readln(now);
  if (flag(now)) then writeln('1')
  else if (now mod 2=1) then
  begin
    if (flag(now-2)) then writeln('2') else writeln('3');
  end
  else writeln('2');
end.
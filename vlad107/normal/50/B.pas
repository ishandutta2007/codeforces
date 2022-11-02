const
  abc='abcdefghijklmnopqrstuvwxyz0123456789';

var
  a:array[1..100] of longint;
  s:ansistring;
  i:longint;
  res:int64;

begin
  fillchar(a,sizeof(a),$0);
  readln(s);
  for i:=1 to length(s) do inc(a[pos(s[i],abc)]);
  res:=0;
  for i:=1 to 36 do inc(res,int64(a[i])*a[i]);
  writeln(res);
end.
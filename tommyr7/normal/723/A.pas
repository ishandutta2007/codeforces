var a,b,c,d,max,min,ans:longint;
begin
  readln(a,b,c);
  max:=a;
  min:=a;
  if (b>max) then max:=b;
  if (c>max) then max:=c;
  if (b<min) then min:=b;
  if (c<min) then min:=c;
  d:=a+b+c-max-min;
  ans:=abs(a-d)+abs(b-d)+abs(c-d);
  writeln(ans);
end.
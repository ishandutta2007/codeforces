uses
  math;

var
  x,y,w,h:longint;
  ans:int64;

begin 
  read(w,h);
  ans:=0;
  for x:=0 to w do
    for y:=0 to h do ans:=ans+int64(min(x,w-x))*min(y,h-y);
  writeln(ans);
end.
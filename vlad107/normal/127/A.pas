var
  n,k,i:longint;
  res:extended;
  x,y:array[0..500500]of longint;

  function dist(x1,y1,x2,y2:extended):Extended;
    begin
      dist:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    end;

begin
  read(n,k);
  for i:=1 to n do read(x[i],y[i]);
  for i:=2 to n do res:=res+dist(x[i],y[i],x[i-1],y[i-1]);
  writeln(res*k/50:0:10);
end.
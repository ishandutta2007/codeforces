uses math;
var x,y,n:qword;
begin
  read(n,x,y);
  writeln(max((y*n-100*x+99)div 100,0));
end.
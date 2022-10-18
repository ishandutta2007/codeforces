var
  x,y:string;
  n,i:longint;
  ok:boolean;

begin
  readln(x);
  readln(y);
  n:=length(x);
  ok:=true;
  for i:=1 to n do
    if x[i]<y[i]
      then ok:=false;
  if ok
    then writeln(y)
    else writeln(-1)
end.
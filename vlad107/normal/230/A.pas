var
  s,n,i,j,tmp:longint;
  x,y:array[0..500500]of longint;

begin
  read(s,n);
  for i:=1 to n do read(x[i],y[i]);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do
      if (x[j]>x[j+1])then begin
        tmp:=x[j];x[j]:=x[j+1];x[j+1]:=tmp;
        tmp:=y[j];y[j]:=y[j+1];y[j+1]:=tmp;
      end;
  for i:=1 to n do 
    if (s<=x[i])then begin
      writeln('NO');
      exit;
    end else inc(s,y[i]);
  writeln('YES');
end.
uses
  math;

var
  ans,n,x1,y1,x2,y2,i:longint;
  x,y,r:array[0..500500]of longint;

  procedure check(tx,ty:longint);
    var
      i:longint;
      
    begin
      inc(ans);
      for i:=1 to n do 
        if ((x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty)<=r[i]*r[i])then begin
          dec(ans);
          exit;
        end;
    end;

begin
  read(x1,y1,x2,y2);
  read(n);
  for i:=1 to n do read(x[i],y[i],r[i]);
  ans:=0;
  for i:=min(x1,x2)+1 to max(x1,x2)-1 do begin
    check(i,y1);
    check(i,y2);
  end;
  for i:=min(y1,y2) to max(y1,y2) do begin
    check(x1,i);
    check(x2,i);
  end;
  writeln(ans);
end.
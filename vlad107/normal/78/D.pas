{$r-,q-,s-,i-,o+}
var
  cd,res,d,x,y,r:int64;
  i:longint;
  function incircle(x,y:int64):boolean;
    begin
      incircle:=x*x+3*y*y<=4*r*r;
    end;
  function ok(x,y:int64):boolean;
    begin
      if (incircle(x+1,y+1))and(incircle(x-1,y+1))and(incircle(x+2,y))and
         (incircle(x-2,y))and(incircle(x+1,y-1))and(incircle(x-1,y-1))
           then ok:=true 
           else ok:=false;
    end;
begin
  read(r);
  x:=0;y:=0;
  d:=1;
  while (ok(x,y+2))do begin
    inc(y,2);
    inc(d);
  end;
  res:=d+d-1;
  i:=0;
//  writeln(d);
//  writeln(ok(6,2));
  while (ok(x+3,0))do begin
    inc(i);
    inc(x,3);
    inc(y);
    if (i and 1=0)then inc(d);
//    writeln(x,' ',y,' ',d);
    while (not ok(x,y))do begin
      dec(y,2);
      dec(d);
    end;
    cd:=d+d;
    if (i and 1=0)then cd:=cd-1;
//    writeln(d);
    res:=res+cd*2;
  end;
  writeln(res);
end.
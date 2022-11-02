var
  x,y,a,b,c,g:int64;
  function gcd(a,b:int64;var x,y:int64):int64;
    var
      x1,y1:int64;
    begin
      if (a=0)then begin
        x:=0;y:=1;
        gcd:=b;
        exit;
      end;
      gcd:=gcd(b mod a,a,x1,y1);
      y:=x1;
      x:=y1 - b div a*x1;
    end;
begin
  read(a,b,c);
  c:=-c;
  g:=gcd(a,b,x,y);
  if (c mod g=0)
    then writeln(x*(c div g),' ',y*(c div g))
    else writeln(-1);
end.
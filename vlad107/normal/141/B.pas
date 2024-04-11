var
  a,x,y:longint;

  function f(x:longint):longint;
    begin
      if (x<3)then f:=x else
      f:=(x+2)shr 1+2*((x-1)shr 1);
    end;

begin
  read(a,x,y);
  if (y mod a=0)then begin
    writeln(-1);
    exit;
  end;
  if (y>2*a)and((y div a)and 1=0)then begin
    if (abs(x)>=a)or(x=0)then begin
      writeln(-1);
      exit;
    end; 
    if (x<0)then writeln(f(y div a)+1)else writeln(f(y div a)+2);
  end else begin
    if (abs(x+x)>=a)then begin
      writeln(-1);
      exit;
    end;
    writeln(f(y div a)+1);
  end;
end.
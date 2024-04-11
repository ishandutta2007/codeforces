var
  res,i,x,y:longint;
  s:ansistring;

begin
  readln(s);
  x:=0;
  for i:=1 to length(s)do x:=x+ord(s[i])-48;
  if (length(s)<2)
    then writeln(0)
    else begin
      res:=1;
      while (x>9)do begin
        y:=0;
        while (x>0)do begin
          y:=y+x mod 10;
          x:=x div 10;
        end;
        x:=y;
        inc(res);
      end;
      writeln(res);
    end;
end.
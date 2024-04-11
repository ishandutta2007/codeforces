{$R-,S-,Q-,I-,O+}
var
  tmp,x1,x2,a,b,d: int64;
begin
  read(x1,x2,a,b);
  if (x2 >= x1+a) and (x2 <= x1+b) then
  begin
    writeln('FIRST');
    writeln(x2);
  end else
  begin
    d:=x2-x1;
    if (d > 0) and (b < 0) then writeln('DRAW') else
    if (d < 0) and (b > 0) then writeln('DRAW') else
    if (a <= 0) and (0 <= b) then writeln('DRAW') else
    begin
      a:=abs(a); b:=abs(b);
      if a > b then begin tmp:=a; a:=b; b:=tmp; end;
      d:=abs(d) mod (a+b);
      if d = 0 then writeln('SECOND') else
      if (d < a) or (d > b) then writeln('DRAW') else
      begin
        writeln('FIRST');
        if x1 < x2 then writeln(x1+d)
        else writeln(x1-d);
      end;
    end;
  end;
end.
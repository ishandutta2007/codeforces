var
  px,py,sx,sy,ex,ey,n,i:longint;
  ch:char;

begin
  readln(n,sx,sy,ex,ey);
  for i:=1 to n do begin
    read(ch);
    px:=sx;py:=sy;
    case ch of 
      'E':inc(sx);
      'S':dec(sy);
      'W':dec(sx);
      'N':inc(sy);
    end;
    if (abs(px-ex)+abs(py-ey)<abs(sx-ex)+abs(sy-ey))then begin
      sx:=px;sy:=py;
    end;
    if (sx=ex)and(sy=ey)then begin
      writeln(i);
      exit;
    end;
  end;
  writeln(-1);
end.
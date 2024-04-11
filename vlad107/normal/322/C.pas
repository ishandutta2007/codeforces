{$r-,q-,s-,i-,o+}
var
  k,x,y,cx,cy,vx,vy:int64;
  i:longint;
  s:ansistring;

begin
  readln(x,y);
  readln(s);
  vx:=0;vy:=0;
  for i:=1 to length(s)do begin
    if (s[i]='U')then inc(vy)else
    if (s[i]='D')then dec(vy)else
    if (s[i]='L')then dec(vx)else
    inc(vx);
  end;
  cx:=0;cy:=0;
  for i:=0 to length(s)Do begin
    if (i<>0)then begin
      if (s[i]='U')then inc(cy)else
      if (s[i]='D')then dec(cy)else
      if (s[i]='L')then dec(cx)else
      inc(cx);
    end;
    if (vx<>0)and((x-cx) mod vx=0)then k:=(x-cx)div vx else
    if (vy<>0)and((y-cy) mod vy=0)then k:=(y-cy)div vy else
    k:=0;
    if (k<0)then continue;
    if (k*vx+cx=x)and(k*vy+cy=y)then begin
      writeln('Yes');
      exit;
    end;
  end;
  writeln('No');
end.
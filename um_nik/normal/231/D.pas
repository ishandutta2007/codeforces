var a1,a2,a3,a4,a5,a6,x1,y1,z1,x,y,z:integer;
begin
readln(x,y,z);
readln(x1,y1,z1);
readln(a1,a2,a3,a4,a5,a6);
if (x>=0) and (x<=x1) then
  begin
  if (y>=0) and (y<=y1) then
    begin
    if (z>=0) and (z<=z1) then
      begin
      
      end;
    if z<0 then
      begin
      writeln(a3);
      end;
    if z>z1 then
      begin
      writeln(a4);
      end;
    end;
  if y<0 then
    begin
    if (z>=0) and (z<=z1) then
      begin
      writeln(a1);
      end;
    if z<0 then
      begin
      writeln(a3+a1);
      end;
    if z>z1 then
      begin
      writeln(a4+a1);
      end;
    end;
  if y>y1 then
    begin
    if (z>=0) and (z<=z1) then
      begin
      writeln(a2);
      end;
    if z<0 then
      begin
      writeln(a2+a3);
      end;
    if z>z1 then
      begin
      writeln(a2+a4);
      end;
    end;
  end;
if x<0 then
  begin
  if (y>=0) and (y<=y1) then
    begin
    if (z>=0) and (z<=z1) then
      begin
      writeln(a5);
      end;
    if z<0 then
      begin
      writeln(a3+a5);
      end;
    if z>z1 then
      begin
      writeln(a4+a5);
      end;
    end;
  if y<0 then
    begin
    if (z>=0) and (z<=z1) then
      begin
      writeln(a1+a5);
      end;
    if z<0 then
      begin
      writeln(a3+a1+a5);
      end;
    if z>z1 then
      begin
      writeln(a4+a1+a5);
      end;
    end;
  if y>y1 then
    begin
    if (z>=0) and (z<=z1) then
      begin
      writeln(a2+a5);
      end;
    if z<0 then
      begin
      writeln(a2+a3+a5);
      end;
    if z>z1 then
      begin
      writeln(a2+a4+a5);
      end;
    end;
  end;
if x>x1 then
  begin
  if (y>=0) and (y<=y1) then
    begin
    if (z>=0) and (z<=z1) then
      begin
      writeln(a6);
      end;
    if z<0 then
      begin
      writeln(a3+a6);
      end;
    if z>z1 then
      begin
      writeln(a4+a6);
      end;
    end;
  if y<0 then
    begin
    if (z>=0) and (z<=z1) then
      begin
      writeln(a1+a6);
      end;
    if z<0 then
      begin
      writeln(a3+a1+a6);
      end;
    if z>z1 then
      begin
      writeln(a4+a1+a6);
      end;
    end;
  if y>y1 then
    begin
    if (z>=0) and (z<=z1) then
      begin
      writeln(a2+a6);
      end;
    if z<0 then
      begin
      writeln(a2+a3+a6);
      end;
    if z>z1 then
      begin
      writeln(a2+a4+a6);
      end;
    end;
  end;
end.
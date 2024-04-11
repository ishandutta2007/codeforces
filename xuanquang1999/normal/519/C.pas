var count, a, b: longint;
begin
 readln(a, b);
 while true do
  begin
   if a >= b then
    begin
     a:=a-2; b:=b-1;
    end
   else
    begin
     a:=a-1; b:=b-2;
    end;
   if (a < 0) or (b < 0) then break; 
   inc(count);
  end;
 writeln(count);
end.
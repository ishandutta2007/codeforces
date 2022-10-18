var
  s:string;
  h,m,i:longint;

begin
  readln(s);
  val(copy(s,1,2),h,i);
  val(copy(s,4,2),m,i);
  for i:=0 to 1440 do
    begin
      if ((h div 10)=(m mod 10))and
         ((h mod 10)=(m div 10))
        then break;
      inc(m);
      if m=60 then
        begin
          m:=0;
          inc(h)
        end;
      if h=24 then h:=0
    end;
  writeln(i)
end.
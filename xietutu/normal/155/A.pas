var x,n,max,min,ans,i:longint;
begin
   readln(n);
   read(max);
   min:=max;
   for i:=2 to n do
    begin
     read(x);
     if x<min then
       begin
        inc(ans);
        min:=x;
       end;
     if x>max then
      begin
       inc(ans);
        max:=x;
      end;
    end;
 writeln(ans);
end.
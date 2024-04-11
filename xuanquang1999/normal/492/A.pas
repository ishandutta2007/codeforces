var i, n, sum, b: longint;
begin
 readln(n);
 sum:=0; b:=0;
 for i:=1 to n+1 do
  begin
   b:=b+i;
   sum:=sum+b;
   if sum > n then break;
  end;
 writeln(i-1);
end.
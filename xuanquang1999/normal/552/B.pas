var n, sum, k, lt: int64;
    i: longint;
    s: string;
begin
 readln(n);
 str(n, s); k:=length(s);
 lt:=9;
 for i:=1 to k-1 do
  begin
   sum:=sum + lt*i;
   lt:=lt*10;
  end;
 lt:=lt div 9 * 10 - 1;
 sum:=sum + (n - lt div 10)*k;
 writeln(sum);
end.
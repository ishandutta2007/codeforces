var n, t, i, j: longint;
    c: char;
    s: string;
begin
 readln(n, t);
 readln(s);

 for i:=1 to t do
  begin
   j:=1;
   while j < n do
    begin
     if (s[j] = 'B') and (s[j+1] = 'G') then
      begin
       c:=s[j]; s[j]:=s[j+1]; s[j+1]:=c;
       inc(j);
      end;
     inc(j);
    end;
  end;

 writeln(s);
end.
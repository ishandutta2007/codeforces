const fi = '';
      fo = '';
      dom: array [1..12] of longint = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
var day1, month1, year1: longint;
    day2, month2, year2, count: longint;

procedure SRead(var day, month, year: longint);
var s, t: string;
    code: longint;
begin
 readln(s);
 val(copy(s, 1, pos(':', s)-1), year, code);
 delete(s, 1, pos(':', s));
 val(copy(s, 1, pos(':', s)-1), month, code);
 delete(s, 1, pos(':', s));
 val(s, day, code);
end;

procedure Swap(var a, b: longint);
var t: longint;
begin
 t:=a; a:=b; b:=t;
end;

procedure Work;
begin
 if (year1 > year2) or ((year1 = year2) and (month1 > month2))
 or ((year1 = year2) and (month1 = month2) and (day1 > day2)) then
  begin
   Swap(year1, year2);
   Swap(month1, month2);
   Swap(day1, day2);
  end;

 while (year1 <> year2) or (month1 <> month2) or (day1 <> day2) do
  begin
   inc(day1);
   if (month1 = 2) and (year1 mod 4 = 0) and ((year1 mod 100 <> 0) or (year1 mod 400 = 0))
   then
    begin
     if day1 > 29 then
      begin
       day1:=1;
       inc(month1)
      end;
    end
   else if (day1 > dom[month1]) then
    begin
     day1:=1;
     inc(month1);
    end;

   if month1 > 12 then
    begin
     month1:=1;
     inc(year1);
    end;
   inc(count);
  end;
 writeln(count);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 SRead(day1, month1, year1);
 SRead(day2, month2, year2);
 Work;

 close(input); close(output);
end.
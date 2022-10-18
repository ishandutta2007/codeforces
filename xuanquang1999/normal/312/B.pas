var a, b, c, d, i: longint;
    chance, acc: double;
begin
 readln(a, b, c, d);
 chance:=0; acc:=a/b;
 for i:=1 to 100000 do
  begin
   chance:=chance + acc;
   acc:=acc*(b-a)*(d-c)/(b*d);
  end;
 writeln(chance:0:6);
end.
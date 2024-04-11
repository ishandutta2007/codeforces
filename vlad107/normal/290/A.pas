const
  a:array[1..40]of string=(
  'Washington','Adams','Jefferson','Madison','Monroe','Adams','Jackson','Van Buren','Harrison','Tyler','Polk','Taylor','Fillmore','Pierce','Buchanan','Lincoln','Johnson','Grant','Hayes','Garfield','Arthur','Cleveland','Harrison','Cleveland','McKinley','Roosevelt','Taft','Wilson','Harding','Coolidge','Hoover','Roosevelt','Truman','Eisenhower','Kennedy','Johnson','Nixon','Ford','Carter','Reagan');
var
  x:longint;
begin
  read(x);
  writeln(a[x]);
end.
var i, j, n, p1, p2: longint;
    s: string;

begin
 readln(s); n:=length(s);
 //if (pos('BAAB', s) > 0) or (pos('BABAB', s) > 0)
 //or ((pos('ABA', s) > 0) and (pos('AB', s) <> pos('ABA', s))) then writeln('YES')
 //else
  begin
   p1:=0;
   for i:=1 to n-1 do
    if copy(s, i, 2) = 'AB' then
     begin
      p1:=i;
      break;
     end;
   p2:=0;
   for i:=1 to n-1 do
    if (copy(s, i, 2) = 'BA') and ((i < p1-1) or (i > p1+1)) then
     begin
      p2:=i;
      break;
     end;
   if (p1 > 0) and (p2 > 0) then
    begin
     writeln('YES');
     exit;
    end;

   p1:=0;
   for i:=1 to n-1 do
    if copy(s, i, 2) = 'BA' then
     begin
      p1:=i;
      break;
     end;
   p2:=0;
   for i:=1 to n-1 do
    if (copy(s, i, 2) = 'AB') and ((i < p1-1) or (i > p1+1)) then
     begin
      p2:=i;
      break;
     end;
   if (p1 > 0) and (p2 > 0) then
    begin
     writeln('YES');
     exit;
    end;

   writeln('NO'); 
  end;

end.
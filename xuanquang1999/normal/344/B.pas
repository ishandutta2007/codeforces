const fi = '';
      fo = '';
var a, b, c, x, y, z: longint;
    found: boolean;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(a, b, c);

 found:=false;
 for x:=0 to a do
  begin
   z:=a-x;
   if z < 0 then continue;
   y:=b-x;
   if y < 0 then continue;
   if y+z <> c then continue;

   writeln(x, ' ', y, ' ', z);
   found:=true;
   break;
  end;

 if not found then writeln('Impossible');

 close(input); close(output);
end.
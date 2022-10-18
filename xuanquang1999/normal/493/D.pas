const fi = '';
      fo = '';
var n: longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 if n mod 2 = 1 then writeln('black')
 else
  begin
   writeln('white');
   writeln('1 2');
  end;


 close(input); close(output);
end.
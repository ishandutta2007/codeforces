const fi = '';
      fo = '';
var n: longint;

procedure Work;
var i, j: longint;
begin
 for i:=n div 7 downto 0 do
  if (n-7*i) mod 4 = 0 then
   begin
    for j:=1 to (n-7*i) div 4 do write(4);
    for j:=1 to i do write(7);
    exit;
   end;
 writeln(-1);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 Work;

 close(input); close(output);
end.
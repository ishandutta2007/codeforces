const fi = '';
      fo = '';
var n, m, i: longint;
    s: string;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, m);

 if n > m then
  begin
   dec(n);
   s:=s+'0';
  end;

 while (n > 0) and (m > n) do
  begin
   dec(n);
   dec(m, 2);
   s:=s+'110';
  end;

 while n > 0 do
  begin
   dec(n);
   dec(m);
   s:=s+'10';
  end;

 if m = 1 then
  begin s:=s+'1'; m:=0; end
 else if m = 2 then
  begin s:=s+'11'; m:=0; end;

 if (m = 0) and (n = 0) then writeln(s)
 else writeln(-1);

 close(input); close(output);
end.
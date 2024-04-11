const fi = '';
      fo = '';
var i, n, k: longint;
    s: string;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do
  begin
   readln(s);
   k:=length(s);
   if (copy(s, 1, 5) = 'miao.') and (copy(s, k-4, 5) = 'lala.') then writeln('OMG>.< I don''t know!')
   else if copy(s, 1, 5) = 'miao.' then writeln('Rainbow''s')
   else if copy(s, k-4, 5) = 'lala.' then writeln('Freda''s')
   else writeln('OMG>.< I don''t know!');
  end;

 close(input); close(output);
end.
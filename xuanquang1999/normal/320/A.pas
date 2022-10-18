const fi = 'input.txt';
      fo = 'output.txt';

var s: string;
    n, i: longint;
    ok: boolean;

begin
 readln(s);
 n:=length(s);
 ok:=true;
 for i:=1 to n do
  if (s[i] <> '1') and (s[i] <> '4') then ok:=false;
 if ok then
  begin
   if (pos('444', s) > 0) or (s[1] = '4') then writeln('NO')
   else writeln('YES');
  end
 else writeln('NO');

 close(input); close(output);
end.
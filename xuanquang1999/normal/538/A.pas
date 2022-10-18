const fi = '';
      fo = '';

var s, t, tmp: string;
    i, j, m, n: longint;

procedure Work;
begin
 for i:=1 to m do
  for j:=i to m do
   begin
    tmp:=s;
    delete(tmp, i, j-i+1);
    if tmp = t then
     begin
      writeln('YES');
      exit;
     end;
   end;
 writeln('NO');
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(s); m:=length(s);
 t:='CODEFORCES'; n:=10;

 Work;

 close(input); close(output);
end.
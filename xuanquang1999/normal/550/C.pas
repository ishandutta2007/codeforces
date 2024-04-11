const fi = '';
      fo = '';
      maxN = 100;
var s, t: string;
    n, k, i, j: longint;
    ok: boolean;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(s); n:=length(s);

 for k:=0 to 124 do
  begin
   str(k*8, t);
   j:=1;
   for i:=1 to n do
    begin
     if s[i] = t[j] then inc(j);
     if j > length(t) then break;
    end;
   if j > length(t) then
    begin
     writeln('YES');
     writeln(t);
     ok:=true;
     break;
    end;
  end;

 if not ok then writeln('NO');

 close(input); close(output);
end.
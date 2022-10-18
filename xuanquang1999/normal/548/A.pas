const fi = '';
      fo = '';
var s, t: ansistring;
    i, j, k, n, l: longint;
    ok: boolean;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(s); n:=length(s);
 readln(k); l:=n div k;

 ok:=true;
 if n mod k <> 0 then ok:=false;
 for i:=1 to k do
  begin
   if not ok then break;
   t:=copy(s, (i-1)*l+1, l);
   for j:=1 to l do
    if t[j] <> t[l+1-j] then
     begin
      ok:=false;
      break;
     end;
  end;

 if ok then writeln('YES')
 else writeln('NO');

 close(input); close(output);
end.
const fi = '';
      fo = '';
var s, t: string;
    i, j, n, cnt: longint;
    p: array [1..100000] of string;
    c: char;
    ok: boolean;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(s);
 n:=length(s);

 cnt:=0;
 for i:=1 to n+1 do
  for c:='a' to 'z' do
   begin
    t:=s; insert(c, t, i);
    ok:=true;
    for j:=1 to cnt do
     if p[j] = t then
      begin
       ok:=false;
       break;
      end;
    if ok then
     begin
      inc(cnt);
      p[cnt]:=t;
     end;
   end;

 writeln(cnt);

 close(input); close(output);
end.
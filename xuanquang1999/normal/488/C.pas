uses math;
const fi = '';
      fo = '';

var HPy, Ay, Dy, HPm, Am, Dm, h, a, d: longint;
    ihp, ia, id, ans: longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(HPy, Ay, Dy);
 readln(HPm, Am, Dm);
 readln(h, a, d);

 ans:=round(1e9);
 for ia:=Dm+1 to 1000 do
  for id:=1 to Am do
   begin
    ihp:=1+(Am-id)*((HPm-1) div (ia-Dm) + 1);
    ans:=min(ans, max(ihp-HPy, 0)*h+max(ia-Ay, 0)*a+max(id-Dy, 0)*d);
   end;

 writeln(ans);
 close(input); close(output);
end.
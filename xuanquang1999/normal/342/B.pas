const fi = '';
      fo = '';
      maxN = 100000;
var n, m, s, f, i, k, dx: longint;
    ch: char;
    t, l, r: array [1..maxN] of longint;

function Between(x, l, r: longint): boolean;
begin
 if (x < l) or (x > r) then exit(false);
 exit(true);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, m, s, f);
 for i:=1 to m do readln(t[i], l[i], r[i]);

 if s < f then
  begin dx:=1; ch:='R'; end
 else
  begin dx:=-1; ch:='L'; end;
 i:=1; k:=1;

 while s <> f do
  begin
   if k = t[i] then
    begin
     if not Between(s, l[i], r[i]) and not Between(s+dx, l[i], r[i]) then
      begin
       write(ch);
       s:=s+dx;
      end
     else write('X');
     inc(i);
    end
   else
    begin
     write(ch);
     s:=s+dx;
    end;
   inc(k);
  end;

 close(input); close(output);
end.
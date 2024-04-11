const fi = '';
      fo = '';

var n, x: int64;
    s, t: string;
    code: integer;
    i, k, cnt: longint;
    ans: array [1..100] of string;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 str(n, s); k:=length(s);
 while true do
  begin
   t:='';
   for i:=1 to k do
    if s[i] > '0' then
     begin
      t:=t+'1';
      s[i]:=chr(ord(s[i])-1);
     end
    else t:=t+'0';
   while t[1] = '0' do delete(t, 1, 1);
   inc(cnt); ans[cnt]:=t;

   val(s, x, code);
   if x = 0 then break;
  end;
 {for i:=65537 downto 1 do
  begin
   val(binstr(i, 17), x, code);
   while n >= x do
    begin
     n:=n-x;
     inc(cnt);
     ans[cnt]:=x;
    end;
  end;}

 writeln(cnt);
 for i:=1 to cnt do write(ans[i], ' ');

 close(input); close(output);
end.
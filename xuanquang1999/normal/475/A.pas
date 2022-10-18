var n, i, j, cnt: longint;
    s: array [1..6] of string;
 
begin
 readln(n);
 
 s[1]:='+------------------------+';
 s[2]:='|#.#.#.#.#.#.#.#.#.#.#.|D|)';
 s[3]:='|#.#.#.#.#.#.#.#.#.#.#.|.|';
 s[4]:='|#.......................|';
 s[5]:='|#.#.#.#.#.#.#.#.#.#.#.|.|)';
 s[6]:='+------------------------+';
 
 cnt:=0;
 for j:=1 to 25 do
  for i:=2 to 5 do
   begin
    if cnt >= n then break;
    if s[i][j] = '#' then 
     begin
      s[i][j]:='O'; inc(cnt);
     end;
   end;
 
 for i:=1 to 6 do writeln(s[i]);
end.
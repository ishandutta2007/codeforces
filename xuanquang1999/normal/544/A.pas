const fi = '';
      fo = '';
var tmp, i, j, cnt, k: longint;
    s: string;
    got: array ['a'..'z'] of boolean;
    pos: array [1..30] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(k);
 readln(s);
 for tmp:=1 to 1 do
  begin
   for i:=1 to length(s) do
    begin
     if cnt = k then break;
     if not got[s[i]] then
      begin
       got[s[i]]:=true;
       inc(cnt); pos[cnt]:=i;
      end;
    end;
   if cnt < k then
    begin
     writeln('NO');
     break;
    end;

   inc(cnt); pos[cnt]:=length(s)+1;
   writeln('YES');
   for i:=1 to cnt-1 do
    begin
     for j:=pos[i] to pos[i+1]-1 do write(s[j]);
     writeln;
    end;
  end;

 close(input); close(output);
end.
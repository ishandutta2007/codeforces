const fi = '';
      fo = '';
      maxN = 1000000;
var i, n, k: longint;
    s: string;

procedure EndProg;
begin
 close(input); close(output);
 halt;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, k);
 if k = 1 then
  begin
   if n = 1 then writeln('a')
   else writeln('-1');
   EndProg;
  end;
 if k > n then
  begin
   writeln('-1');
   EndProg;
  end;

 if (n-k) mod 2 = 0 then
  begin
   for i:=1 to (n-k) div 2 do s:=s+'ab';
   for i:=1 to k do s:=s+chr(i+96);
  end
 else
  begin
   for i:=1 to (n-k+1) div 2 do s:=s+'ab';
   s:=s+'a';
   for i:=3 to k do s:=s+chr(i+96);
  end;

 writeln(s);

 close(input); close(output);
end.
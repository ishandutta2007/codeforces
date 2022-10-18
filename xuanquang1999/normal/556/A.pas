const fi = '';
      fo = '';
var s: string;
    i, n, cnt0, cnt1: longint;
    
begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n); 
 readln(s);
 
 for i:=1 to n do
  if s[i] = '1' then inc(cnt1)
  else inc(cnt0);
  
 writeln(abs(cnt1-cnt0));
 
 close(input); close(output);
end.
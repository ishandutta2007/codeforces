const fi = '';
      fo = '';
var n, i: longint;
    c: char;
    s: string;
    cnt: array [0..1, 'a'..'b'] of int64;
    ans0, ans1: int64;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(s); n:=length(s);

 for i:=1 to n do inc(cnt[i mod 2, s[i]]);

 for c:='a' to 'b' do ans0:=ans0 + cnt[0, c]*cnt[1, c];
 for i:=0 to 1 do
  for c:='a' to 'b' do ans1:=ans1 + (cnt[i, c]*(cnt[i, c]+1)) div 2;

 writeln(ans0, ' ', ans1);

 close(input); close(output);
end.
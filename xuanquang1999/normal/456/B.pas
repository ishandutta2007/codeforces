const fi = '';
      fo = '';
      maxN = 100000;
      e = 5;
var i, ans, l, n: longint;
    s: array [1..maxN] of char;
    code: integer;

function pow(x, n: longint): longint;
var i, ans: longint;
begin
 ans:=1;
 for i:=1 to n do
  ans:=(ans*x) mod e;
 exit(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 while not eoln do
  begin
   inc(l);
   read(s[l]);
  end;

 if l >= 2 then val(copy(s, l-1, 2), n, code)
 else val(copy(s, 1, 1), n, code);

 for i:=1 to 4 do ans:=ans+pow(i, n);
 writeln(ans mod e);

 close(input); close(output);
end.
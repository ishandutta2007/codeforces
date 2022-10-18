const fi = '';
      fo = '';
      maxN = 100000;
var n, i: longint;
    a: array [1..maxN] of longint;
    c: char;
    ok: boolean;

procedure Swap(var a, b: longint);
var t: longint;
begin
 t:=a; a:=b; b:=t;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 while not eoln do
  begin
   inc(n);
   read(c);
   a[n]:=ord(c)-48;
  end;

 ok:=false;
 for i:=1 to n do
  if (a[i] mod 2 = 0) and (a[n] > a[i]) then
   begin
    Swap(a[i], a[n]);
    ok:=true;
    break;
   end;

 if not ok then
  for i:=n downto 1 do
   if a[i] mod 2 = 0 then
    begin
     Swap(a[i], a[n]);
     ok:=true;
     break;
    end;

 if not ok then writeln(-1)
 else for i:=1 to n do write(a[i]);

 close(input); close(output);
end.
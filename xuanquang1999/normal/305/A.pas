const fi = '';
      fo = '';
var n, i, j, k, l: longint;
    a: array [1..100] of longint;

procedure Stop;
begin
 close(input); close(output);
 halt;
end;

function Check(x1, x2, x3, x4: longint): boolean;
var i, cnt: longint;
begin
 for i:=1 to 3 do
  begin
   cnt:=0;
   if (x1 mod 10 = 0) then inc(cnt);
   if (x2 mod 10 = 0) then inc(cnt);
   if (x3 mod 10 = 0) then inc(cnt);
   if (x4 mod 10 = 0) then inc(cnt);
   if cnt < 3 then exit(false);
   x1:=x1 div 10; x2:=x2 div 10; x3:=x3 div 10; x4:=x4 div 10;
  end;
 exit(true);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 for i:=1 to n do read(a[i]);

 for i:=1 to n do
  for j:=i+1 to n do
   for k:=j+1 to n do
    for l:=k+1 to n do
     if Check(a[i], a[j], a[k], a[l]) then
      begin
       writeln(4);
       writeln(a[i], ' ', a[j], ' ', a[k], ' ', a[l]);
       Stop;
      end;

 for i:=1 to n do
  for j:=i+1 to n do
   for k:=j+1 to n do
    if Check(a[i], a[j], a[k], 0) then
     begin
      writeln(3);
      writeln(a[i], ' ', a[j], ' ', a[k]);
      Stop;
     end;

 for i:=1 to n do
  for j:=i+1 to n do
   if Check(a[i], a[j], 0, 0) then
    begin
     writeln(2);
     writeln(a[i], ' ', a[j]);
     Stop;
    end;

 writeln(1);
 writeln(a[1]);

 close(input); close(output);
end.
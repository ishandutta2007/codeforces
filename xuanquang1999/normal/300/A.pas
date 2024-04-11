var i, n: longint;
    a: array [1..100] of longint;
    free: array [1..100] of boolean;

procedure Work1;
var i: longint;
begin
 for i:=1 to n do
  if a[i] < 0 then
   begin
    writeln('1 ', a[i]);
    free[i]:=false;
    break;
   end;
end;

procedure Work2;
var i, count: longint;
begin
 for i:=1 to n do
  if a[i] > 0 then
   begin
    writeln('1 ', a[i]);
    free[i]:=false;
    exit;
   end;
 write('2 ');

 count:=0;
 for i:=1 to n do
  if free[i] and (a[i] < 0) then
   begin
    write(a[i], ' ');
    free[i]:=false;
    inc(count); if count = 2 then break;
   end;
 writeln;
end;

procedure Work3;
var i, count: longint;
begin
 count:=0;
 for i:=1 to n do
  if free[i] then inc(count);
 write(count, ' ');
 for i:=1 to n do
  if free[i] then write(a[i], ' ');
end;

begin
 fillchar(free, sizeof(free), true);
 readln(n);
 for i:=1 to n do read(a[i]);

 Work1;
 Work2;
 Work3;

end.
uses math;
const fi = '';
      fo = '';
      maxN = 100000;
var a: array [1..maxN+5] of longint;
    n, count: longint;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
end;

procedure Work;
var k, b, i, j, l: longint;
begin
 count:=a[1]; k:=a[1]; b:=1;
 for i:=2 to n do
  begin
   if a[i] <> a[i-1] then
    begin
     while b > 0 do
      begin
       if b and 1 = 0 then inc(count);
       b:=b shr 1;
       inc(k); if k = a[i] then break;
      end;
     count:=count + a[i] - k;
     k:=a[i];
     inc(b);
    end
   else inc(b);
  end;

 while b > 0 do
  begin
   if b and 1 = 0 then inc(count);
   b:=b shr 1;
  end;
end;

procedure Answer;
begin
 writeln(count);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.
const fi = '';
      fo = '';
      maxN = 200000;
var n, q, count1, count2: longint;
    a: array [1..maxN] of longint;

procedure Enter;
var i: longint;
begin
 readln(n, q);
 for i:=1 to n do
  begin
   read(a[i]);
   if a[i] = -1 then inc(count1)
   else inc(count2);
  end;
end;

function Check(n: longint): boolean;
begin
 if n mod 2 = 1 then exit(false);
 if (count1 < n div 2) or (count2 < n div 2) then exit(false);
 exit(true);
end;

procedure Work;
var i, l, r: longint;
begin
 for i:=1 to q do
  begin
   readln(l, r);
   if check(r-l+1) then writeln(1)
   else writeln(0);
  end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
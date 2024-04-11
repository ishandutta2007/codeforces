const fi = '';
      fo = '';
      maxN = 100;
var a: array [1..maxN, 1..maxN] of char;
    n: longint;

procedure Enter;
var i, j: longint;
begin
 readln(n);
 for i:=1 to n do
  begin
   for j:=1 to n do
    begin
     read(a[i, j]);
     if a[i, j] = '.' then a[i, j]:='S';
    end;
   readln;
  end;
end;

procedure Work;
var i, j, k: longint;
    r, c: array [1..maxN] of longint;
    ok: boolean;
begin
 fillchar(r, sizeof(r), 0);
 fillchar(c, sizeof(c), 0);
 for i:=1 to n do
  for j:=1 to n do
   if a[i, j] = 'S' then
    begin
     inc(r[i]);
     inc(c[j]);
    end;
 for i:=1 to n do
  for j:=1 to n do
   if (r[i] = 0) and (c[j] = 0) then
    begin
     writeln(-1);
     exit;
    end;

 for i:=1 to n do
  for j:=1 to n do
   if a[i, j] = 'S' then
    begin
     dec(r[i]);
     dec(c[j]);
     ok:=true;
     if r[i] = 0 then
      for k:=1 to n do
       if c[k] = 0 then ok:=false;
     if c[j] = 0 then
      for k:=1 to n do
       if r[k] = 0 then ok:=false;
     if not ok then
      begin
       inc(r[i]);
       inc(c[j]);
      end
     else a[i, j]:='.';
    end;

 for i:=1 to n do
  for j:=1 to n do
   if a[i, j] = 'S' then writeln(i, ' ', j);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
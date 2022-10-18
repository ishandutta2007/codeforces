const fi = '';
      fo = '';
      maxN = 100;
var a: array [1..maxN, 1..maxN] of char;
    s: array [1..maxN] of string;
    m, n, count: longint;

procedure Enter;
var i, j: longint;
begin
 readln(m, n);
 for i:=1 to m do
  begin
   for j:=1 to n do read(a[i, j]);
   readln;
  end;
end;

procedure Work;
var ok: boolean;
    i, j: longint;
begin
 count:=0;
 for i:=1 to m do s[i]:='';
 for j:=1 to n do
  begin
   ok:=true;
   for i:=1 to m-1 do
    if s[i]+a[i, j] > s[i+1]+a[i+1, j] then
     begin
      ok:=false;
      break;
     end;
   if not ok then
    begin
     inc(count);
     continue;
    end;
   for i:=1 to m do s[i]:=s[i]+a[i, j];
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
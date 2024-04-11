const fi = '';
      fo = '';
var x, a: array [1..4] of longint;
    n: longint;

function Check: boolean;
var i, j: longint;
    free: array [1..4] of boolean;
    ok: boolean;
begin
 if (x[1]+x[2]+x[3]+x[4] <> 2*(x[2]+x[3])) or (x[1]+x[2]+x[3]+x[4] <> 4*(x[4]-x[1])) or (x[2]+x[3] <> 2*(x[4]-x[1])) then exit(false);
 for i:=1 to 3 do
  if x[i] > x[i+1] then exit(false);
 fillchar(free, sizeof(free), true);
 for i:=1 to n do
  begin
   ok:=false;
   for j:=1 to 4 do
    if free[j] and (a[i] = x[j]) then
     begin
      free[j]:=false;
      ok:=true;
      break;
     end;
   if not ok then exit(false);
  end;

 writeln('YES');
 for i:=1 to 4 do
  if free[i] then writeln(x[i]);
 exit(true);
end;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
end;

procedure Work;
var i, j: longint;
begin
 for i:=1 to 1500 do
  begin
   x[1]:=i;
   x[4]:=3*x[1];
   for j:=1 to 4*x[1]-1 do
    begin
     x[2]:=j;
     x[3]:=4*x[1]-x[2];
     if Check then exit;
    end;
  end;
 writeln('NO');
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
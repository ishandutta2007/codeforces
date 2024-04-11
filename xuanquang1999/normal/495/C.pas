uses math;
const fi = '';
      fo = '';
      maxN = 100000;
var s: array [1..maxN] of char;
    a, p, ans: array [0..maxN] of longint;
    n, np: longint;

procedure Enter;
var c: char;
begin
 n:=0; np:=0;
 while true do
  begin
   read(c);
   if (c <> '(') and (c <> ')') and (c <> '#') then break;
   inc(n); s[n]:=c;
  end;
end;

function Work: boolean;
var i, count: longint;
begin
 a[0]:=0;
 for i:=1 to n do
  begin
   if s[i] = '(' then a[i]:=a[i-1]+1
   else
    begin
     a[i]:=a[i-1]-1;
     if s[i] = '#' then
      begin
       inc(np);
       p[np]:=i;
       ans[np]:=1;
      end;
    end;
   if a[i] < 0 then exit(false);
  end;

 for i:=p[np] to n-1 do
  begin
   a[i]:=a[i]-a[n];
   if a[i] < 0 then exit(false);
  end;
 for i:=1 to np-1 do writeln(1);
 writeln(1+a[n]);
 exit(true);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 if not Work then writeln(-1);

 close(input); close(output);
end.
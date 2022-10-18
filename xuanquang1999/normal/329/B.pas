const fi = '';
      fo = '';
      maxN = 1000+5;
      r: array [1..4] of longint = (-1, 0, 1, 0);
      c: array [1..4] of longint = (0, 1, 0, -1);
var m, n, first, last, xS, yS, time: longint;
    a: array [1..maxN, 1..maxN] of char;
    d: array [0..maxN+1, 0..maxN+1] of longint;
    Qx, Qy: array [1..sqr(maxN)] of longint;

procedure Enter;
var i, j: longint;
begin
 readln(m, n);
 for i:=1 to m do
  begin
   for j:=1 to n do
    begin
     read(a[i, j]);
     if a[i, j] = 'E' then
      begin
       xS:=i; yS:=j;
      end;
    end;
   a[i, n+1]:='T';
   readln;
  end;
end;

procedure Push(x, y: longint);
begin
 inc(last);
 Qx[last]:=x; Qy[last]:=y;
end;

procedure Pop(var x, y: longint);
begin
 x:=Qx[first]; y:=Qy[first];
 inc(first);
end;

function BFS1: longint;
var i, x, y, u, v: longint;
begin
 for x:=1 to m do
  for y:=1 to n do d[x, y]:=-1;

 first:=1; last:=0;
 Push(xS, yS);
 d[xS, yS]:=0;
 while first <= last do
  begin
   Pop(x, y);
   for i:=1 to 4 do
    begin
     u:=x+r[i]; v:=y+c[i];
     if (d[u, v] = -1) and (a[u, v] <> 'T') then
      begin
       Push(u, v);
       d[u, v]:=d[x, y]+1;
       if a[u, v] = 'S' then exit(d[u, v]);
      end;
    end;
  end;
end;

procedure BFS2;
var i, x, y, u, v, ans, tmp: longint;
    code: integer;
begin
 for x:=1 to m do
  for y:=1 to n do d[x, y]:=-1;
 ans:=0;

 first:=1; last:=0;
 Push(xS, yS);
 d[xS, yS]:=0;
 while first <= last do
  begin
   Pop(x, y);
   for i:=1 to 4 do
    begin
     u:=x+r[i]; v:=y+c[i];
     if (d[u, v] = -1) and (a[u, v] <> 'T') then
      begin
       Push(u, v);
       d[u, v]:=d[x, y]+1;
       if d[u, v] <= time then
        begin
         val(a[u, v], tmp, code);
         if code = 0 then ans:=ans+tmp;
        end;
      end;
    end;
  end;
 writeln(ans);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 time:=BFS1;
 BFS2;

 close(input); close(output);
end.
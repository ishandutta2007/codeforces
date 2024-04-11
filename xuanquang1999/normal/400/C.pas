const fi = '';
      fo = '';
      maxN = 100000;
var x, y: array [1..maxN] of longint;
    m, n, a, b, c, p: longint;

procedure Enter;
var i: longint;
begin
 readln(m, n, a, b, c, p);
 for i:=1 to p do readln(x[i], y[i]);
end;

procedure Swap(var a, b: longint);
var t: longint;
begin
 t:=a; a:=b; b:=t;
end;

procedure Rotate;
var i, tx, ty: longint;
begin
 for i:=1 to p do
  begin
   tx:=x[i]; ty:=y[i];
   x[i]:=ty; y[i]:=m-tx+1;
  end;
 Swap(m, n);
end;

procedure MirrorY;
var i: longint;
begin
 for i:=1 to p do
  y[i]:=n-y[i]+1;
end;

procedure Work;
var i: longint;
begin
 for i:=1 to (a+3) mod 4 + 1 do Rotate;
 for i:=1 to b mod 2 do MirrorY;
 for i:=1 to 3 - (c+3) mod 4 do Rotate;
end;

procedure Answer;
var i: longint;
begin
 for i:=1 to p do writeln(x[i], ' ', y[i]);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.
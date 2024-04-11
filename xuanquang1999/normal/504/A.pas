const fi = '';
      fo = '';
      maxN = 1 shl 16;
var a, b: array [0..maxN-1] of longint;
    Queue: array [1..maxN] of longint;
    ansu, ansv: array [1..maxN] of longint;
    n, m, first, last: longint;

procedure Enter;
var i: longint;
begin
 readln(n);
 for i:=0 to n-1 do readln(a[i], b[i]);
end;

procedure Push(i: longint);
begin
 inc(last); Queue[last]:=i;
end;

function Pop: longint;
begin
 Pop:=Queue[first]; inc(first);
end;

procedure Work;
var i, u, v: longint;
begin
 first:=1; last:=0;
 for u:=0 to n-1 do
  if a[u] = 1 then Push(u);
 while first <= last do
  begin
   u:=Pop; v:=b[u];
   if a[u] = 0 then continue;
   inc(m); ansu[m]:=u; ansv[m]:=v;
   dec(a[v]); dec(a[u]); b[v]:=b[v] xor u;
   if a[v] = 1 then Push(v);
  end;
end;

procedure Answer;
var i: longint;
begin
 writeln(m);
 for i:=1 to m do
  writeln(ansu[i], ' ', ansv[i]);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;
 Answer;

 close(input); close(output);
end.
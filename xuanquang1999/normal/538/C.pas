uses math;
const fi = '';
      fo = '';
      maxN = 100005;
var n, m: longint;
    d, h: array [0..maxN] of longint;

procedure Enter;
var i: longint;
begin
 readln(n, m);
 for i:=1 to m do readln(d[i], h[i]);
end;

procedure Work;
var i, maxH, h1, h2: longint;
begin
 maxH:=max(h[1]+d[1]-1, h[m]+n-d[m]);
 for i:=1 to m-1 do
  begin
   h1:=max(h[i], h[i+1]); h2:=min(h[i], h[i+1]);
   if h1-h2 > d[i+1]-d[i] then
    begin
     writeln('IMPOSSIBLE');
     exit;
    end;
   maxH:=max(maxH, h1 + (d[i+1]-d[i]-(h1-h2)) div 2);
  end;
 writeln(maxH);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.
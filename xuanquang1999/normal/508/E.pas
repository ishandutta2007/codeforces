const fi = '';
      fo = '';
      maxN = 600;
var i, n, top, k: longint;
    p, l, r, st: array [1..maxN] of longint;
    s: ansistring;

procedure Push(v: longint);
begin
 inc(top); st[top]:=v;
end;

procedure Pop;
begin
 dec(top);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 s:=''; top:=0; k:=1; i:=0;
 while i <= n do
  begin
   if (top > 0) and (length(s)+1-p[top] >= l[top]) then
    begin
     if length(s)+1-p[top] > r[top] then break;
     dec(top);
     s:=s + ')';
    end
   else if i < n then
    begin
     inc(top);
     readln(l[top], r[top]);
     s:=s + '(';
     p[top]:=length(s);
     inc(i);
    end
   else break;
  end;

 if length(s) < 2*n then writeln('IMPOSSIBLE')
 else writeln(s);

 close(input); close(output);
end.
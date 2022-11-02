{$r-,q-,s-,i-,o+}
var
  s : array [1..100] of string;
  tmp, a, b, x, y, i, j, n : longint;
  p : string;
  nom, w, e, q : array [1..100] of longint;

  function nn(x : string) : longint;
    var
      i : longint;
    begin
      i := 1;
      while (s[i] <> x) do inc(i);
      nn := i;
    end;

begin
{  assign(input, 'input.txt'); reset(input);
  assign(output, 'output.txt'); rewrite(output);}
  readln(n);
  for i:=1 to n do
    readln(s[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do begin
      readln(p);
      x := nn(copy(p, 1, pos('-', p)-1));
      delete(p, 1, pos('-', p));
      y := nn(copy(p, 1, pos(' ', p)-1));
      delete(p, 1, pos(' ', p));
      val(copy(p, 1, pos(':', p)-1), a);
      delete(p, 1, pos(':', p));
      val(p, b);
      if (a > b)
       then inc(q[x], 3)
       else
      if (a < b)
       then inc(q[y], 3)
       else
      if (a=b) then begin
        inc(q[x]); inc(q[y]);
      end;
      inc(w[x], a-b);
      inc(w[y], b-a);
      inc(e[x], a);
      inc(e[y], b);
    end;
  for i:=1 to n do nom[i] := i;
  for j:=1 to n-1 do
    for i:=1 to n-1 do
      if (q[i] < q[i+1]) or
         (q[i] = q[i+1]) and (w[i] < w[i+1]) or
         (q[i] = q[i+1]) and (w[i] = w[i+1]) and (e[i] < e[i+1])
           then begin
             tmp := q[i]; q[i] := q[i+1]; q[i+1] := tmp;
             tmp := w[i]; w[i] := w[i+1]; w[i+1] := tmp;
             tmp := e[i]; e[i] := e[i+1]; e[i+1] := tmp;
             tmp := nom[i]; nom[i] := nom[i+1]; nom[i+1] := tmp;
           end;
  n := n shr 1;
  for j:=1 to n-1 do
    for i:=1 to n-1 do
      if (s[nom[i]] > s[nom[i+1]]) then begin
        tmp := nom[i]; nom[i] := nom[i+1]; nom[i+1] := tmp;
      end;
  for i:=1 to n do
    writeln(s[nom[i]]);
end.